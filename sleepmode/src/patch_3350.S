#if defined(J108_R7EA011)
    .equ func, 0x144CF304
    .equ ret, 0x141E0064
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
    ldr     r0, [sp, #0x10]
    add     sp, sp, #0x1C
    pop     {r4-r7, pc}

.align 2

killtimer:
    add     r4, r4, #1
    lsl     r4, r4, #0x18
    lsr     r4, r4, #0x18
    cmp     r4, #8
    bcc     _ret
    bl      KillRefreshTimer
    pop     {r3-r7, pc}

_ret:
    ldr     r3, =ret+1
    bx      r3
