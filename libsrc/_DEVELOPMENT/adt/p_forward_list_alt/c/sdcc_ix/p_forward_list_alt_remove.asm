
; void *p_forward_list_alt_remove(p_forward_list_alt_t *list, void *item)

SECTION code_clib
SECTION code_adt_p_forward_list_alt

PUBLIC _p_forward_list_alt_remove

EXTERN asm_p_forward_list_alt_remove

_p_forward_list_alt_remove:

   pop af
   pop hl
   pop bc
   
   push bc
   push hl
   push af

   jp asm_p_forward_list_alt_remove
