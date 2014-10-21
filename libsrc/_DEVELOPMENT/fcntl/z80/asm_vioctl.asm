
; ===============================================================
; May 2014
; ===============================================================
; 
; int vioctl(int fd, uint16_t request, void *arg)
;
; Sends configuration messages to the underlying driver.
;
; ===============================================================

INCLUDE "clib_cfg.asm"

SECTION seg_code_fcntl

PUBLIC asm_vioctl

EXTERN STDIO_MSG_ICTL
EXTERN l_jpix, __stdio_nextarg_bc, __fcntl_fdstruct_from_fd_2
EXTERN error_enotsup_mc, error_mc, __fcntl_fdchain_descend

asm_vioctl:

   ; enter : hl = int fd
   ;         bc = request
   ;            = xxxx xxxx xxxx x000 = forward to driver
   ;            = xxxx xxxx xxxx xDDD = if DDD does not match driver type, error
   ;            = 00xx xxxx xxxx xDDD = forward to driver
   ;            = 01xx xxxx xxxx xDDD = get flags (one bits in 13..3)
   ;            = 10xx xxxx xxxx xDDD = set flags (one bits in 13..3) using parameter
   ;            = 11xx xxxx xxxx xDDD = boolean flags (one bits in 13..3) using true/false parameter
   ;         de = void *arg
   ;
   ; exit  : success
   ;
   ;            ix = FDSTRUCT* corresponding to receiving device
   ;            hl = return value
   ;            carry reset
   ;
   ;         fail
   ;
   ;            hl = -1
   ;            carry set, errno set
   ;
   ; uses  : af, bc, de, hl, ix
   
   push de                     ; save void *arg
   
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
IF __CLIB_OPT_MULTITHREAD & $08

   EXTERN __fcntl_lock_fdtbl
   call __fcntl_lock_fdtbl

ENDIF
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

   call __fcntl_fdstruct_from_fd_2
   pop hl                      ; hl = void *arg

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
IF __CLIB_OPT_MULTITHREAD & $08

   EXTERN __fcntl_unlock_fdtbl
   call __fcntl_unlock_fdtbl

ENDIF
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

   jp c, error_mc              ; if fd is invalid

   ; ix = FDSTRUCT *
   ; bc = request
   ; hl = void *arg

    ld a,c
    and $07
    
    scf
    jr z, deliver_message      ; if request is not handled by stdio

find_driver_loop:

   ld a,(ix+6)                 ; a = FDSTRUCT.flags
   xor c
   and $07
   jr z, deliver_message       ; if message_type == driver_type
   
   call __fcntl_fdchain_descend
   jr nz, find_driver_loop     ; if there is another FDSTRUCT in chain

   jp error_enotsup_mc         ; message rejected

deliver_message:

   ld e,c
   ld d,b

   ; ix = FDSTRUCT *
   ; de = request
   ; hl = void *arg
   ; carry set if request not handled by stdio

   call __stdio_nextarg_bc     ; bc = first parameter
   jr c, forward_ioctl         ; if request is not handled by stdio

   ; stdio handles request automatically
   ; check request type
   
   ld a,d
   rlca
   rlca
   and $03                     ; a = 00 fwd, 01 getf, 10 setf, 11 bool
   jr z, forward_ioctl         ; if flag type is forward

   ; ix = FDSTRUCT *
   ; bc = parameter
   ; de = request
   ; hl = void *arg

   dec a
   jr z, __getf

   dec a
   jr z, __setf

__bool:

   ld a,b
   or c
   jr z, __setf
   
   ld bc,$ffff

__setf:

   ; ix = FDSTRUCT *
   ; bc = parameter
   ; de = request
   ; hl = void *arg

   push bc
   push de
   
   call forward_ioctl          ; forward to driver
   
   pop de
   pop bc

   ld l,(ix+9)
   ld h,(ix+10)                ; hl = FDSTRUCT.ioctl_flags
   
   ld a,d
   and $3f
   ld d,a                      ; will not affect bits 15..14
   
   ld a,e
   and $f8
   ld e,a                      ; will not affect bits 2..0   

   and c
   ld c,a
   ld a,d
   and b
   ld b,a                      ; bc = bc & de = final value of affected bits
   
   ld a,e
   cpl
   and l
   or c
   ld (ix+9),a
   
   ld a,d
   cpl
   and h
   or b
   ld (ix+10),a                ; write new value of driver flags
   
   ret

__getf:

   ; ix = FDSTRUCT *
   ; de = request

   ld a,e
   and (ix+9)
   ld l,a
   
   ld a,d
   and (ix+10)
   ld h,a
   
   ret

forward_ioctl:

   ; ix = FDSTRUCT *
   ; bc = parameter
   ; de = request
   ; hl = void *arg

   ld a,STDIO_MSG_ICTL
   call l_jpix

   ret nc   
   jp error_mc                 ; indicate error
