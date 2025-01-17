#ifdef C510_R1HA035
    .equ db_RET,0x14CC0E2E+1
    .equ GUIObject_SoftKeys_SetVisible,0x141C4E24+1
    .equ GUIObject_SoftKeys_SetText,0x141C50C8+1
    .equ GUIObject_SoftKeys_SetAction,0x1417BACC+1

    .equ action_back,0x144C0684+1

    .equ text_play,0x631
    .equ text_pause,0x1390
    .equ text_stop,0xCC0
#endif

    .extern db_action_pause

    // softkey_action
    .section .text.softkey_action
    .thumb
    .word   db_action_pause

    // softkey_text
    .section .text.softkey_text
    .thumb
    .word   text_pause

    // add_new_softkeys
    .section .text.add_new_softkeys
    .thumb
    ldr     r3, =softkey_add+1
    bx      r3

    // Patch function
    .section .text.patch_section
    .thumb
softkey_add:
    ldr     r2, =text_play
    mov     r1, #0xFF
    ldr     r0, [r6,#0x14]
    ldr     r3, =GUIObject_SoftKeys_SetText
    blx     r3
    ldr     r2, =db_action_pause
    mov     r1, #0xFF
    ldr     r0, [r6,#0x14]
    ldr     r3, =GUIObject_SoftKeys_SetAction
    blx     r3
    mov     r2, #0
    mov     r1, #0xFF
    ldr     r0, [r6,#0x14]
    ldr     r3, =GUIObject_SoftKeys_SetVisible
    blx     r3
    ldr     r2, =text_stop
    ldr     r1, =0xFC0
    ldr     r0, [r6,#0x14]
    ldr     r3, =GUIObject_SoftKeys_SetText
    blx     r3
    ldr     r2, =action_back
    ldr     r1, =0xFC0
    ldr     r0, [r6,#0x14]
    ldr     r3, =GUIObject_SoftKeys_SetAction
    blx     r3
    ldr     r3, =db_RET
    bx      r3