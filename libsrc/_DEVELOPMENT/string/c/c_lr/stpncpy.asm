
XLIB stpncpy

LIB asm_stpncpy

stpncpy:

   pop af
   pop bc
   pop hl
   pop de
   
   push de
   push hl
   push bc
   push af
   
   jp asm_stpncpy
