#if defined(C510_R1HA035)
    .equ softkeys_hook_ret, 0x14CE0CF8
    .equ original_softkeys, 0x1542B118

    .equ GUIObject_SoftKeys_SetAction, 0x1417BACC
    .equ GUIObject_SoftKeys_SetText, 0x141C50C8
    .equ LAYOUT_TEXTID, 0x1862
    .equ ACTION_ID, 0xFC0
#elif defined(W760_R3EM001)
    .equ softkeys_hook_ret, 0x10E76552
    .equ original_softkeys, 0x10E76630

    .equ GUIObject_SoftKeys_SetAction, 0x108AE74C
    .equ GUIObject_SoftKeys_SetText, 0x108AE7C4
    .equ LAYOUT_TEXTID, 0x1B0F
    .equ ACTION_ID, 0xFC2
#endif

// Softkeys Hook
.section .text.softkeys_hook
.thumb
    ldr r3, =fd_softkeys+1
    bx r3

// Patch function
.section .text.patch_section
.thumb
fd_softkeys:
    ldr r2, =original_softkeys+1
    ldr r1, =ACTION_ID
    ldr r0, [r4, #0x18]
    ldr r3, =GUIObject_SoftKeys_SetAction+1
    blx r3
    ldr r2, =LAYOUT_TEXTID
    mov r1, #1
    ldr r0, [r4, #0x18]
    ldr r3, =GUIObject_SoftKeys_SetText+1
    blx r3
    ldr r2, =FlashmenuPicker
    mov r1, #1
    ldr r0, [r4, #0x18]
    ldr r3, =GUIObject_SoftKeys_SetAction+1
    blx r3
    ldr r3, =softkeys_hook_ret+1
    bx r3
