#if defined(C510_R1HA035)
    .equ _ddb_question_ret, 0x14CB7000+1
    .equ _file_handler_ret, 0x14DDAB02+1
    .equ FILEITEM_GetPath, 0x142C7CA0+1
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
    .word Close_DataDownloadBook

@ Patch function
.section .text.patch_section
.thumb
_ddb_question:
    add     r0, r4, #0
    bl      Patch_ReplaceFile_Page
    ldr     r3, =_ddb_question_ret
    bx      r3

.align 2

.section .text.patch_section
.thumb
_file_handler:
    bl      New_ReplaceFile
    ldr     r0, [r5, #0]
    ldr     r3, =FILEITEM_GetPath
    blx     r3
    ldr     r3, =_file_handler_ret
    bx      r3
