#if defined(C510_R1HA035)
    .equ ongoingcallbook_onclose, 0x14F604FC
#elif defined(W760_R3EM001)
    .equ ongoingcallbook_onclose, 0x10E93FE0
#elif defined(W810_R4EA031)
    .equ ongoingcallbook_onclose, 0x454096C8
#endif

.section .text.dispdesc_hook
.thumb
    .word New_Volume_OnCreate
    .word New_Volume_OnClose
    .word New_Volume_OnRedraw

.section .text.on_enter_hook
.thumb
    .word New_Volume_OnEnter

.section .text.patch_section
.thumb
.global is_ongoingcallbook
.type is_ongoingcallbook, %function
is_ongoingcallbook:
    ldr     r1, =ongoingcallbook_onclose+1
    ldr     r0, [r0, #4]
    cmp     r0, r1
    beq     .1
    mov     r0, #0
    bx      lr
.1:
    mov     r0, #1
    bx      lr
