#if defined(K600_R2BB001)
    .equ func, 0x202651A8
    .equ DispObject_SetBacklightMode, 0x20267D8C
#elif defined(W810_R4EA031)
    .equ func, 0x453035A8
    .equ TextID_Destroy, 0x452FE86C
    .equ DispObject_SetBacklightMode, 0x453066AC
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
#if defined(DB2010)
    add     r0, r4, #0
#endif
    ldr     r3, =DispObject_SetBacklightMode+1
    blx     r3
    add     r0, r4, #0
    bl      SetRefreshTimer
    mov     r0, #1
    pop     {r4-r7, pc}

.align 2

killtimer:
#if defined(DB2010)
    ldr     r3, =TextID_Destroy+1
    blx     r3
#endif
    ldr     r3, =func+1
    blx     r3
    bl      KillRefreshTimer
    pop     {r4, r5, pc}
