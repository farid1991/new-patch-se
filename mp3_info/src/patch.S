#if defined(C510_R1HA035)
    .equ TextID_Create, 0x141818E4
#elif defined(J108_R7EA011)
    .equ TextID_Create, 0x145B8610
#elif defined(W760_R3EM001)
    .equ TextID_Create, 0x10FFBF40
#endif

.section .text.brw_mp3_hook
.thumb
    ldr    r3, =brw_mp3_info+1
    bx     r3

.section .text.patch_section
.thumb
brw_mp3_info:
#if defined(DB3200) || defined(DB3210)
    mov    r2, #6
#endif
    mov    r1, #5
    add    r0, sp, #8
    ldr    r3, =TextID_Create+1
    blx    r3
    add    r1, r4, #0
    bl     patch_brw_mp3info
    str    r0, [r5, #0]
    mov    r0, #0
    add    sp, #0x20
#if defined(DB3350)
    pop    {r4-r6, pc}
#else
    pop    {r4-r7, pc}
#endif
