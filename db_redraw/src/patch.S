#if defined(W810_R4EA031)
    .equ SOFTKEY_TEXT_ID0, 0x4FA
    .equ SOFTKEY_TEXT_ID1, 0xFE0

    .equ MediaPlayer_SoftKey_SetAction, 0x45074FAC
    .equ MediaPlayer_SoftKey_SetText, 0x45074FE0
    .equ GUIObject_Softkey_SetAction, 0x4519B824
    .equ GUIObject_Softkey_SetText, 0x4519B90C
    .equ GUIObject_SoftKey_SetVisible, 0x4519B9A4
    .equ GUIObject_Show, 0x45193E64

    .equ IsAudioPlayerBook, 0x4542FF58
    .equ FindBook, 0x45531160

    .equ softkeys_minim_ret, 0x4543220E
    .equ softkeys_maxim_ret, 0x45247BDA
#endif

.section .text.patch_MediaPlayer_SingleFile_Enter
    .word New_MediaPlayer_SingleFile_Enter

.section .text.patch_MediaPlayer_SingleFile_Exit
    .word New_MediaPlayer_SingleFile_Exit

.section .text.patch_BookObj_SetFocus
.thumb
    push    {lr}
    ldr     r3, =New_BookObj_SetFocus+1
    blx     r3
    pop     {pc}

.section .text.patch_MediaPlayer_SoftKeys
    ldr     r0, =softkeys_minim+1
    bx      r0

.section .text.patch_DataBrowser_SoftKeys
    ldr     r1, =softkeys_maxim+1
    bx      r1

.section .text.patch_section
.thumb
softkeys_minim:
    ldr     r0, [r4, #0x1C]
    ldr     r2, =New_Mediaplayer_SoftKeys
    mov     r1, #0x24
    ldr     r3, =MediaPlayer_SoftKey_SetAction+1
    blx     r3
    ldr     r0, [r4, #0x1C]
    ldr     r2, =SOFTKEY_TEXT_ID0
    mov     r1, #0x24
    ldr     r3, =MediaPlayer_SoftKey_SetText+1
    blx     r3
    ldr     r0, [r4, #0x1C]
    add     r2, r5, #0
    add     r1, r6, #0
    ldr     r3, =softkeys_minim_ret+1
    bx      r3

.align 2

softkeys_maxim:
    ldr     r0, [r5]
    ldr     r2, =New_DataBrowser_SoftKeys
    mov     r1, #0xFF
    ldr     r3, =GUIObject_Softkey_SetAction+1
    blx     r3
    ldr     r0, [r5]
    ldr     r2, =SOFTKEY_TEXT_ID1
    mov     r1, #0xFF
    ldr     r3, =GUIObject_Softkey_SetText+1
    blx     r3
    ldr     r0, =IsAudioPlayerBook+1
    bl      FindBook
    cmp     r0, #0
    bne     setenabled
    mov     r2, #0
    b       procsoft

setenabled:
    mov     r2, #1

procsoft:
    ldr     r0, [r5]
    mov     r1, #0xFF
    ldr     r3, =GUIObject_SoftKey_SetVisible+1
    blx     r3
    ldr     r0, [r5]
    ldr     r3, =GUIObject_Show+1
    blx     r3
    ldr     r0, =#0x2B4
    ldr     r3, =softkeys_maxim_ret+1
    bx      r3
