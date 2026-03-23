#if defined(U10_R7AA071)
    .equ _ddb_question_ret, 0x15952736
    .equ _file_handler_ret, 0x15952BE4
    .equ DataDownload_Main_Page, 0x15CFCD10
#elif defined(U100_R7AA076)
    .equ _ddb_question_ret, 0x1571479A
    .equ _file_handler_ret, 0x15714C48
    .equ DataDownload_Main_Page, 0x15AA228C
#endif

@ Close DataDownloadBook
.section .text.ddb_close
    .word New_DataDownloadBook_onClose

@ Question handler hook
.section .text.ddb_question
.thumb
    ldr     r3, =_ddb_question+1
    bx      r3

@ File handler hook fix
.section .text.ddb_filefix
.thumb
    nop
    nop

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
    ldr     r1, =DataDownload_Main_Page
    bl      Patch_ReplaceFile_Page
    mov     r0, #0
    str     r0, [sp, #0x1C]
    ldr     r3, =_ddb_question_ret+1
    bx      r3

.align 2

_file_handler:
    ldr     r0, [r4, #0x1C]
    bl      New_ReplaceFile
    ldr     r0, [r4, #0x1C]
    ldr     r3, =_file_handler_ret+1
    bx      r3
