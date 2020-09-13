//-----------------------------------------------------------------------------
// z80asm restart
// Copyright (C) Paulo Custodio, 2011-2020
// License: The Artistic License 2.0, http://www.perlfoundation.org/artistic_license_2_0
//-----------------------------------------------------------------------------

#include "legacy.h"

#include "errors.h"
#include "fileutil.h"
#include "libfile.h"
#include "modlink.h"
#include "utlist.h"
#include "zobjfile.h"

char Z80libhdr[] = "Z80LMF" OBJ_VERSION;

/*-----------------------------------------------------------------------------
*	define a library file name from the command line
*----------------------------------------------------------------------------*/
static const char* search_libfile(const char* filename ) {
    if ( filename != NULL && *filename != '\0' )	/* not empty */
        return GetLibFilename( filename );		/* add '.lib' extension */
    else {
        error_not_lib_file(filename);
        return NULL;
    }
}

/*-----------------------------------------------------------------------------
*	make library from list of files; convert each source to object file name
*----------------------------------------------------------------------------*/
void make_library(const char* lib_filename, size_t num_files, const char* files[]) {
    ByteArray* obj_file_data;
    FILE*	lib_file;
    const char* obj_filename;
    size_t	 fptr, obj_size;

    lib_filename = search_libfile(lib_filename);
    if ( lib_filename == NULL )
        return;					/* ERROR */

    if (OptionVerbose())
        printf("Creating library '%s'\n", path_canon(lib_filename));

    /* write library header */
    lib_file = xfopen( lib_filename, "wb" );
    xfwrite_cstr(Z80libhdr, lib_file);

    /* write each object file */
    for (size_t i = 0; i < num_files; i++) {
        fptr = ftell( lib_file );

        /* read object file */
        obj_filename = GetOFilename(files[i]);
        obj_file_data = read_obj_file_data( obj_filename );
        if ( obj_file_data == NULL ) {
            xfclose(lib_file);			/* error */
            remove(lib_filename);
            return;
        }

        /* write file pointer of next file, or -1 if last */
        obj_size = ByteArray_size( obj_file_data );
        if (i + 1 == num_files)
            xfwrite_dword(-1, lib_file);
        else
            xfwrite_dword(fptr + 4 + 4 + obj_size,  lib_file);

        /* write module size */
        xfwrite_dword(obj_size, lib_file);

        /* write module */
        xfwrite_bytes((char*)ByteArray_item(obj_file_data, 0), obj_size, lib_file);
    }

    /* close and write lib file */
    xfclose( lib_file );
}

bool check_library_file(const char* src_filename) {
    return check_obj_lib_file(
               GetLibFilename(src_filename),
               Z80libhdr,
               error_not_lib_file,
               error_lib_file_version);
}
