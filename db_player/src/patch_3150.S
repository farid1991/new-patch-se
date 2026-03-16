#if defined(W760_R3EM001)
    .equ STR_MID, 0x11FDBDCA
    .equ wstrncmp, 0x107992C8
    .equ CreateKeyGrabber, 0x10A702C8
    .equ FILEITEM_GetFextension, 0x1188FBC0
    .equ _return_fw, 0x1187AB48
#endif

.section .text.sound_run_hook
.thumb
    ldr     r3, =sound_run+1
    bx      r3

.section .text.patch_section
.thumb
sound_run:
    ldr     r0, [r6, #4]
    ldr     r3, =FILEITEM_GetFextension+1
    blx     r3
    ldr     r1, =STR_MID
    mov     r2, #3
    ldr     r3, =wstrncmp+1
    blx     r3
    cmp     r0, #0
    beq     is_mid
    add     r1, r5, #0
    add     r0, r4, #0
    bl      CreateInfo
    b       _exit
is_mid:
    add     r0, r5, #0
    ldr     r3, =CreateKeyGrabber+1
    blx     r3
    str     r0, [r6, #0x14]
    cmp     r0, #0
    beq     _exit
    ldr     r3, =_return_fw+1
    bx      r3

_exit:
    mov     r0, #1
    pop     {r4-r7, pc}
