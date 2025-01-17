#if defined(C510_R1HA035)
    .equ DDB_Question_RET, 0x14CB7000+1
    .equ FileHandler_RET, 0x14DDAB02+1
    .equ FILEITEM_GetPath, 0x142C7CA0+1
#endif

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

    // Close DataDownloadBook
    .section .text.ddb_close
    .word   Close_DataDownloadBook

    // Patch function
    .section .text.patch_section
    .thumb
_DDB_Question:
    add     r0, r4, #0
    bl      Patch_ReplaceFile_Page
    ldr     r3, =DDB_Question_RET
    bx      r3

    .align 2

    .section .text.patch_section
    .thumb
_File:
    bl      New_ReplaceFile
    ldr     r0, [r5,#0]
    ldr     r3, =FILEITEM_GetPath
    blx     r3
    ldr     r3, =FileHandler_RET
    bx      r3