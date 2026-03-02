#if defined(W760_R3EM001)
    .equ func, 0x10A6D7E0
    .equ ret_01, 0x10984A28
    .equ ret_02, 0x10984AA8
#endif

.section .text.timer_set_hook
.thumb
    ldr     r3, =settimer+1
    bx      r3

.section .text.timer_kill_hook
.thumb
    ldr     r3, =killtimer+1
    bx      r3

.section .text.redraw_hook
.thumb
    .word New_SleepMode_OnRedraw

@ Patch function
.section .text.patch_section
.thumb
settimer:
    ldr     r3, =func+1
    blx     r3
    add     r0, r4, #0
    bl      SetRefreshTimer
    mov     r0, sp
    ldrb    r0, [r0, #0x8]
    ldr     r3, =ret_01+1
    bx      r3

.align 2

killtimer:
    cmp     r5, #0xD
    bcc     _loop
    bl      KillRefreshTimer
    pop     {r4-r7, pc}

_loop:
    ldr     r3, =ret_02+1
    bx      r3
