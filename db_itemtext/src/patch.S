#if defined(C510_R1HA035)
    .equ return_hook, 0x1574717A
#elif defined(J108_R7EA011)
    .equ return_hook, 0x148F34AC
#elif defined(W760_R3EM001)
    .equ return_hook, 0x11875A00
#endif

#if defined(DB3150v2)
.section .text.secondline_hook_fix
.thumb
    nop
#endif

.section .text.secondline_hook
.thumb
    ldr     r3, =dir_secondline+1
    bx      r3

@ Patch function
.section .text.patch_section
.thumb
dir_secondline:
#if defined(DB3150v2) || defined(DB3200)|| defined(DB3210)
    add     r0, r5, #0
    add     r1, r6, #0
    bl      db_set_secondline_text
    str     r0, [r4]
#elif defined(DB3350)
    ldr     r1, =0x78000020
    add     r0, r6, #0
    bl      db_set_secondline_text
#endif
    ldr     r3, =return_hook+1
    bx      r3
