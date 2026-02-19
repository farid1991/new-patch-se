#if defined(J108_R7EA011)
    .equ volume_hook_RET, 0x146DC77A+1
    .equ GUIObject_SoftKeys_SetAction, 0x1455ADF0+1
    .equ GUIObject_SoftKeys_SetText, 0x14559DC4+1
    .equ SOFTKEYS_ID, 0x2
    .equ RECORD_TEXTID, 0x151
#endif

@ Softkeys Visibility Hook
.section .text.volume_hook
.thumb
    ldr     r3, =new_softkeys+1
    bx      r3

@ Patch function
.section .text.patch_section
.thumb
new_softkeys:
    ldr     r2, =0x14F51B54+1
    ldr     r0, [r4, #0x1c]
    sub     r1, r5, #1
    ldr     r3, =GUIObject_SoftKeys_SetAction
    blx     r3
    ldr     r0, [r4, #0x1c]
    ldr     r2, =RECORD_TEXTID
    mov     r1, #SOFTKEYS_ID
    ldr     r3, =GUIObject_SoftKeys_SetText
    blx     r3
    ldr     r0, [r4, #0x1c]
    ldr     r2, =Call_vs
    mov     r1, #SOFTKEYS_ID
    ldr     r3, =GUIObject_SoftKeys_SetAction
    blx     r3
    ldr     r3, =volume_hook_RET
    bx      r3
