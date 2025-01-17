#if defined(C510_R1HA035)
    .equ alarmlist_b, 0x1517A71E+1
    .equ alarmstandby_RET, 0x141ACA38+1
#endif

    // ALARM_LIST
    .section .text.alarmlist
    .thumb
    add     r0, r5, #0
    add     r0, #0x54
    ldr     r3, =GetRemainingTimeID
    blx     r3
    str     r0, [sp,#0xC]
    b       alarmlist_b

    // ALARM_STANDBY
    .section .text.alarmstandby
    .thumb
    ldr     r3, =alarm_standby+1
    bx      r3

    // Patch function
    .section .text.patch_section
    .thumb
alarm_standby:
    mov     r0, sp
    add     r0, sp, #0xC
    bl      GetRemainingTimeID
    str     r0, [sp,#4]
    ldr     r3, =alarmstandby_RET
    bx      r3