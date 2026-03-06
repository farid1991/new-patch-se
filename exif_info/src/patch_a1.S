#if defined(W810_R4EA031)
    .equ TextID_Create, 0x452FE69C
#endif

.section .text.brw_jpg_hook
.thumb
    ldr     r3, =brw_jpg_info+1
    bx      r3

.section .text.patch_section
.thumb
brw_jpg_info:
    mov     r2, #6
    mov     r1, #5
    mov     r0, sp
    ldr     r3, =TextID_Create+1
    blx     r3
    add     r1, r4, #0
    bl      patch_brw_jpg_info
    str     r0, [r5]
    mov     r0, #0
    add     sp, #0x3C
    pop     {r4-r6, pc}
