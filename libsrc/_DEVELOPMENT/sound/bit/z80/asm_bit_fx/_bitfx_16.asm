
SECTION seg_code_sound_bit

PUBLIC _bitfx_16

INCLUDE "clib_target_cfg.asm"

_bitfx_16:

   ; blirp

   ld b,255

expl:

   push af
   
   ld a,__sound_bit_toggle
   ld h,0
   ld l,b
   and (hl)
   ld l,a
   
   pop af
   
   xor l
   INCLUDE "sound/bit/z80/output_bit_device_2.inc"

   push bc

dly:

   nop
   djnz dly
   
   pop bc
   
   push af
   
   ld a,__sound_bit_toggle
   ld h,0
   ld l,b
   and (hl)
   ld l,a
   
   pop af
   
   xor l
   INCLUDE "sound/bit/z80/output_bit_device_2.inc"

   push bc
   push af
   
   ld a,255
   sub b
   ld b,a
   
   pop af

dly2:

   nop
   djnz dly2
   
   pop bc
   djnz expl
   
   ret
