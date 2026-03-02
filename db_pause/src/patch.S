#if defined(C510_R1HA035)
    .equ db_new_softkeys_ret, 0x14CC0E2E
    .equ GUIObject_SoftKeys_SetVisible, 0x141C4E24
    .equ GUIObject_SoftKeys_SetText, 0x141C50C8
    .equ GUIObject_SoftKeys_SetAction, 0x1417BACC

    .equ action_back, 0x144C0684

    .equ text_play, 0x631
    .equ text_pause, 0x1390
    .equ text_stop, 0xCC0
#elif defined(W760_R3EM001)
    .equ db_new_softkeys_ret, 0x1187AB6E
    .equ GUIObject_SoftKeys_SetVisible, 0x108AE848
    .equ GUIObject_SoftKeys_SetText, 0x108AE7C4
    .equ GUIObject_SoftKeys_SetAction, 0x108AE74C

    .equ action_back, 0x1187AA7C

    .equ text_play, 0x707
    .equ text_pause, 0x76B
    .equ text_stop, 0x5C1
#endif

.extern db_action_pause

@ softkey_action
.section .text.softkey_action
.thumb
    .word db_action_pause

@ softkey_text
.section .text.softkey_text
.thumb
    .word text_pause

@ add_new_softkeys
.section .text.add_new_softkeys
.thumb
    ldr     r3, =db_new_softkeys+1
    bx      r3

@ Patch function
.section .text.patch_section
.thumb
db_new_softkeys:
    ldr     r2, =text_play
    mov     r1, #0xFF
    ldr     r0, [r6, #0x14]
    ldr     r3, =GUIObject_SoftKeys_SetText+1
    blx     r3
    ldr     r2, =db_action_pause
    mov     r1, #0xFF
    ldr     r0, [r6, #0x14]
    ldr     r3, =GUIObject_SoftKeys_SetAction+1
    blx     r3
    mov     r2, #0
    mov     r1, #0xFF
    ldr     r0, [r6, #0x14]
    ldr     r3, =GUIObject_SoftKeys_SetVisible+1
    blx     r3
    ldr     r2, =text_stop
    ldr     r1, =0xFC0
    ldr     r0, [r6, #0x14]
    ldr     r3, =GUIObject_SoftKeys_SetText+1
    blx     r3
    ldr     r2, =action_back+1
    ldr     r1, =0xFC0
    ldr     r0, [r6, #0x14]
    ldr     r3, =GUIObject_SoftKeys_SetAction+1
    blx     r3
    ldr     r3, =db_new_softkeys_ret+1
    bx      r3
