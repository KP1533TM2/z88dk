
; ===============================================================
; Oct 2014
; ===============================================================
; 
; _Noreturn void _exit(int status)
;
; "The _Exit() and _exit() functions shall be equivalent."
;
; Exit the program without running the exit stack.
;
; ===============================================================

SECTION seg_code_fcntl

PUBLIC asm__exit

EXTERN _Exit

defc asm__exit = _Exit
