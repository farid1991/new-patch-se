#if defined(C510_R1HA035)
    .equ func, 0x144677A8
    .equ ret, 0x142F11BA
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
    mov     r1, #1
    ldr     r3, =func+1
    blx     r3
    add     r0, r4, #0
    bl      SetRefreshTimer
    mov     r0, sp
    ldrb    r0, [r0]
    add     sp, sp, #0x10
    pop     {r4-r7, pc}

.align 2

killtimer:
    add     r5, r5, #1
    lsl     r5, r5, #0x18
    lsr     r5, r5, #0x18
    cmp     r5, #0xD
    bcc     _ret
    bl      KillRefreshTimer
    pop     {r3-r7, pc}

_ret:
    ldr     r3, =ret+1
    bx      r3
