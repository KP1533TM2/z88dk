
; int fputc_unlocked(int c, FILE *stream)

SECTION code_stdio

PUBLIC _fputc_unlocked

_fputc_unlocked:

   pop af
   pop de
   pop ix
   
   push hl
   push de
   push af
   
   INCLUDE "stdio/z80/asm_fputc_unlocked.asm"
