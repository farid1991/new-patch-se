#if defined(U10_R7AA071)
    .equ alarmlist_RET, 0x1412D250+1
    .equ alarmstandby_RET, +1
#elif defined(U100_R7AA076)
    .equ alarmlist_RET, 0x14129470+1
    .equ alarmstandby_RET, 0x145C7E64+1
#endif

    // ALARM_LIST
    .section .text.alarmlist
    .thumb
    ldr     r3, =alarm_list+1
    bx      r3

    // ALARM_STANDBY
    .section .text.alarmstandby
    .thumb
    ldr     r3, =alarm_standby+1
    bx      r3

    .section .text.patch_section
    .thumb
alarm_list:
    bl      GetRemainingTimeID
    str     r0, [SP,#0x1C]
    mov     r0, #1
    str     r0, [SP,#0x18]
    ldr     r3, =alarmlist_RET 
    bx      r3

    // Patch function
    .section .text.patch_section
    .thumb
alarm_standby:
    mov     r0, sp
    add     r0, sp, #0x10
    bl      GetRemainingTimeID
    ldr     r3, =alarmstandby_RET
    bx      r3