#if defined(W810_R4EA031)
    .equ TextID_Create, 0x452FE69C
#endif

.section .text.brw_mp3_hook
.thumb
    ldr     r3, =brw_mp3_info+1
    bx      r3

.section .text.patch_section
.thumb
brw_mp3_info:
    add     r5, r5, #1
    lsl     r2, r5, #0x10
    lsr     r2, r2, #0x10
    mov     r1, #5
    add     r0, sp, #4
    ldr     r3, =TextID_Create+1
    blx     r3
    add     r1, r4, #0
    bl      patch_brw_mp3info
    ldr     r1, [sp, #0x58]
    str     r0, [r1]
    mov     r0, #0
    add     sp, #0x5C
    pop     {r4-r7, pc}
