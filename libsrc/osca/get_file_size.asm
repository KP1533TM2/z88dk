;
;	Old School Computer Architecture - interfacing FLOS
;	Stefano Bodrato, 2011
;
;	Get the size for the given file
;
;	$Id: get_file_size.asm,v 1.5 2016-06-22 22:13:09 dom Exp $
;

    INCLUDE "flos.def"

        SECTION code_clib
	PUBLIC  get_file_size
	PUBLIC  _get_file_size
	
get_file_size:
_get_file_size:
; __FASTCALL__, HL points to filename
	push	ix	;save callers
	push	iy
	call	kjt_find_file
	push	ix
	pop		de
	push	iy
	pop		hl
	pop		iy
	pop	ix	;restore callers
	ret	z

	ld	hl,0
	ld	d,h
	ld	e,l
	ret
