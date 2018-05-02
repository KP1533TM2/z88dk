/*
Z88DK Z80 Macro Assembler

Utilities working files.

Copyright (C) Gunther Strube, InterLogic 1993-99
Copyright (C) Paulo Custodio, 2011-2017
License: The Artistic License 2.0, http://www.perlfoundation.org/artistic_license_2_0
Repository: https://github.com/pauloscustodio/z88dk-z80asm
*/

#pragma once

#include "die.h"

#include "types.h"
#include "str.h"
#include "utarray.h"
#include <stdio.h>

/*-----------------------------------------------------------------------------
*   Pathname manipulation
*   All filenames are returned in strpool
*	Input string is unchanged.
*	Basename is file name removing all directories.
*	Dirname is the path up to and including the final slash.
*	Extension is the final "." followed by sequence of letters or digits
*----------------------------------------------------------------------------*/
extern char *path_remove_ext( char *filename );
extern char *path_replace_ext( char *filename, char *new_ext );
extern char *path_basename( char *filename );
extern char *path_dirname( char *filename );

extern char *path_remove_slashes(char *filename);

/* search for a file on the given directory list, return full path name */
extern void path_search( Str *dest, char *filename, UT_array *dir_list );
extern char *search_file(char *filename, UT_array *dir_list);	/* returned string in strpool */

/* check if file/directory exists */
extern bool file_exists(char *filename);
extern bool dir_exists(char *dirname);
extern int file_size(char *filename);	// file size, -1 if not regular file

/* create a directory and all parents above it */
extern void mkdir_p(char *path);
