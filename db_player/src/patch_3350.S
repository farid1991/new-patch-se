#if defined(J108_R7EA011)
    .equ STR_MID, 0x146E0D28
    .equ wstrncmp, 0x145C5BA0
    .equ CreateKeyGrabber, 0x14816D18
    .equ FILEITEM_GetFextension, 0x1402112C
    .equ _return_fw, 0x14816C76
#endif

.section .text.sound_run_hook_fix
.thumb
    nop

.section .text.sound_run_hook
.thumb
    ldr     r3, =sound_run+1
    bx      r3

.section .text.mme_data_fix
.thumb
    .word Get_MME_DATA

.section .text.patch_section
.thumb
sound_run:
    ldr     r0, [r4, #4]
    ldr     r3, =FILEITEM_GetFextension+1
    blx     r3
    ldr     r1, =STR_MID @ L"mid"
    mov     r2, #3
    ldr     r3, =wstrncmp+1
    blx     r3
    cmp     r0, #0
    beq     is_mid
    ldr     r0, [sp, #8]
    bl      CreateInfo
    b       _exit
is_mid:
    ldr     r0, [sp, #8]
    ldr     r3, =CreateKeyGrabber+1
    blx     r3
    str     r0, [r4, #0x14]
    cmp     r0, #0
    beq     _exit
    ldr     r3, =_return_fw+1
    bx      r3
_exit:
    mov     r0, #1
    pop     {r1-r7, pc}
