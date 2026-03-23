#if defined(U10_R7AA071)
    .equ _ddb_question_ret, 0x15952736+1
    .equ _file_handler_ret, 0x15952BE4+1
#elif defined(U100_R7AA076)
    .equ _ddb_question_ret, 0x1571479A+1
    .equ _file_handler_ret, 0x15714C48+1
#endif

@ Close DataDownloadBook
.section .text.ddb_close
    .word Close_DataDownloadBook

@ Question handler hook
.section .text.ddb_question
.thumb
    ldr     r3, =_ddb_question+1
    bx      r3

@ File handler hook
.section .text.ddb_file
.thumb
    ldr     r3, =_file_handler+1
    bx      r3

@ Patch function
.section .text.patch_section
.thumb
_ddb_question:
    ldr     r0, [sp, #0x18]
    bl      Patch_ReplaceFile_Page
    mov     r0, #0
    str     r0, [sp, #0x1C]
    ldr     r3, =_ddb_question_ret
    bx      r3

.align 2

_file_handler:
    ldr     r0, [r4, #0x1C]
    bl      New_ReplaceFile
    ldr     r0, [r4, #0x1C]
    ldr     r3, =_file_handler_ret
    bx      r3
