
    SECTION code_l_sccz80
    PUBLIC  l_i64_asr_u
    PUBLIC  l_i64_asr_uo
    EXTERN  __i64_acc
    EXTERN  l_lsr_dehldehl

; Entry: __i64_acc = shift count
;        sp + 2    = value to shift

l_i64_asr_u:
    ld    a,(__i64_acc+0)
l_i64_asr_uo:
    pop   bc
    pop   hl
    pop   de
    exx
    pop   hl
    pop   de
    exx
    push  bc
    call  l_lsr_dehldehl
    ld    (__i64_acc+0),hl
    ld    (__i64_acc+2),de
    exx
    ld    (__i64_acc+4),hl
    ld    (__i64_acc+6),de
    ret
