#if defined(J108_R7EA011)
    .equ StatusRow_p, 0x4BC34430
    .equ action_back, 0x1479E610
    .equ end_pg_ObEx_FileSent, 0x146BDD44
    .equ end_pg_ObEx_FileSentFailed, 0x14D07686

    .equ DispObject_InvalidateRect, 0x144D7100
    .equ obexreceivebook_onclose, 0x14810CBC
#elif defined(W760_R3EM001)
    .equ StatusRow_p, 0x4BBC5AEC
    .equ action_back, 0x10941708
    .equ end_pg_ObEx_FileSent, 0x1094181C
    .equ end_pg_ObEx_FileSentFailed, 0x10941888

    .equ DispObject_InvalidateRect, 0x10A6653C
    .equ obexreceivebook_onclose, 0x1093FCF0
#endif

.section .text.StatusRow_OnRedraw
.thumb
    .word New_StatusRow_OnRedraw

.section .text.ObEx_ReceiveFile
.thumb
    .word New_ObEx_ReceiveFile

.section .text.ObEx_SendFile
.thumb
    .word New_ObEx_SendFile

.section .text.ObEx_SendMultipleFiles
.thumb
#if defined(DB3350)
    .word New_ObEx_SendMultipleFiles
#else
    .word New_ObEx_SendFile
#endif

.section .text.ObEx_FileSent
.thumb
    .word New_ObEx_FileSent

.section .text.pg_ObEx_FileSent
.thumb
    mov r1, #0
    add r0, r5, #0
    bl action_back
    b end_pg_ObEx_FileSent

.section .text.pg_ObEx_FileSentFailed
.thumb
    add r0, r4, #0
    bl action_back
    b end_pg_ObEx_FileSentFailed

.section .text.patch_section
.thumb
.global refresh_statusrow
.type refresh_statusrow, %function
refresh_statusrow:
    push {lr}
    ldr r0, =StatusRow_p
    ldr r0, [r0]
    mov r1, #0
    ldr r3, =DispObject_InvalidateRect+1
    blx r3
    pop {pc}

.section .text.patch_section
.thumb
.global is_obexreceivebook
.type is_obexreceivebook, %function
is_obexreceivebook:
    ldr r1, =obexreceivebook_onclose+1
    ldr r0, [r0, #4]
    cmp r0, r1
    bne notequal
    mov r0, #1
    bx lr
notequal:
    mov r0, #0
    bx lr
