#if defined(U10_R7AA071)
    .equ DDB_Question_RET, 0x15952736+1
    .equ FileHandler_RET, 0x15952BE4+1
#elif defined(U100_R7AA076)
    .equ DDB_Question_RET, 0x1571479A+1
    .equ FileHandler_RET, 0x15714C48+1
#endif

    // Close DataDownloadBook
    .section .text.ddb_close
    .word   Close_DataDownloadBook

    // Question handler hook
    .section .text.ddb_question
    .thumb
    ldr     r3, =_DDB_Question+1
    bx      r3

    // File handler hook
    .section .text.ddb_file
    .thumb
    ldr     r3, =_File+1
    bx      r3

    // Patch function
    .section .text.patch_section
    .thumb
_DDB_Question:
    ldr     r0, [sp,#0x18]
    bl      Patch_ReplaceFile_Page
    mov     r0, #0
    str     r0, [sp,#0x1C]
    ldr     r3, =DDB_Question_RET
    bx      r3

    .align 2

_File:
    ldr     r0, [r4,#0x1C]
    bl      New_ReplaceFile
    ldr     r0, [r4,#0x1C]
    ldr     r3, =FileHandler_RET
    bx      r3