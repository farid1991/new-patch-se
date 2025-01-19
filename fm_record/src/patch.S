#if defined(C510_R1HA035)
    .equ softkeys_hook_RET, 0x1554AB4A+1
    .equ softkeys_vis_RET, 0x1554AC8A+1

    .equ GUIObject_SoftKeys_SetAction, 0x1417BACC+1
    .equ GUIObject_SoftKeys_SetText, 0x141C50C8+1
    .equ GUIObject_SoftKeys_SetVisible, 0x141C4E24+1
    .equ SOFTKEYS_ID, 0x12
    .equ RECORD_TEXTID, 0x502
#endif

    // Softkeys Hook
    .section .text.fm_sk_hook
    .thumb
    ldr     r3, =softkeys_hook+1
    bx      r3

    // Softkeys Visibility Hook
    .section .text.fm_sk_vis_hook
    .thumb
    ldr     r3, =softkeys_vis+1
    bx      r3

    // Patch function
    .section .text.patch_section
    .thumb
softkeys_hook:
    ldr     r0, [r4,#0x18]
    add     r2, r5, #0
    mov     r1, #7
    ldr     r3, =GUIObject_SoftKeys_SetAction
    blx     r3
    ldr     r0, [r4,#0x18]
    ldr     r2, =RECORD_TEXTID
    mov     r1, #SOFTKEYS_ID
    ldr     r3, =GUIObject_SoftKeys_SetText
    blx     r3
    ldr     r0, [r4,#0x18]
    ldr     r2, =FMRadio_Record
    mov     r1, #SOFTKEYS_ID
    ldr     r3, =GUIObject_SoftKeys_SetAction
    blx     r3
    ldr     r3, =softkeys_hook_RET
    bx      r3

    .align 2

    .section .text.patch_section
    .thumb
softkeys_vis:
    ldr     r0, [r4,#0x18]
    mov     r1, #5
    add     r2, r5, #0
    ldr     r3, =GUIObject_SoftKeys_SetVisible
    blx     r3
    ldr     r0, [r4,#0x18]
    mov     r1, #SOFTKEYS_ID
    add     r2, r5, #0
    ldr     r3, =GUIObject_SoftKeys_SetVisible
    blx     r3
    ldr     r3, =softkeys_vis_RET
    bx      r3