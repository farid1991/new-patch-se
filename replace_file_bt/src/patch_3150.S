#if defined(W760_R3EM001)
    .equ _ddb_question_ret, 0x1188CC64
    .equ _file_handler_ret, 0x1188D234
    .equ FILEITEM_GetPath, 0x1188FC50
    .equ pages_offset, 0x84
#endif

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

@ Close DataDownloadBook
.section .text.ddb_close
    .word New_DataDownloadBook_onClose

@ Patch function
.section .text.patch_section
.thumb
_ddb_question:
    add     r0, r4, #0
    add     r1, #pages_offset
    bl      Patch_ReplaceFile_Page
    ldr     r3, =_ddb_question_ret+1
    bx      r3

.align 2

.section .text.patch_section
.thumb
_file_handler:
    ldr     r0, [r5]
    bl      New_ReplaceFile
    ldr     r0, [r5]
    ldr     r3, =FILEITEM_GetPath+1
    blx     r3
    ldr     r3, =_file_handler_ret+1
    bx      r3
