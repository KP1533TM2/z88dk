;
;       VZ C Library
;
;	Print character to the screen
;
;       We will corrupt any register
;
;       We print over 16 lines at 32 columns
;
;       Stefano Bodrato - Apr.2000
;
;
;	$Id: fputc_cons.asm,v 1.2 2001-04-13 14:14:00 stefano Exp $
;


          XLIB  fputc_cons

;
; Entry:        hl points char to print
;

; 193 Inverse characters starting from "@".
; 64  "@" char (as normal).
; 127-192 Pseudo-Graphics Chars (like ZX81)


.fputc_cons
	ld	hl,2
	add	hl,sp
	ld	a,(hl)
	; Some undercase text?  Transform in UPPER !
	cp	97
	jr	c,nounder
	sub	32
	jr	setout
.nounder
	; Transform the UPPER to INVERSE TEXT
	; Naah! That was orrible!
	;cp	65
	;jr	c,noupper
	;add	a,128
.noupper
	; Some more char remapping can stay here...
.setout
	call	826
	ret

