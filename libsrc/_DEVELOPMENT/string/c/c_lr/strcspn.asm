
XLIB strcspn

LIB asm_strcspn

strcspn:

   pop af
   pop de
   pop hl
   
   push hl
   push de
   push af
   
   jp asm_strcspn
