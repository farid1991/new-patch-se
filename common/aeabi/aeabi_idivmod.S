/*
 * __aeabi_idivmod.S
 */

.syntax unified
.arm
.globl __aeabi_idivmod
.type __aeabi_idivmod, %function
.align 4

__aeabi_idivmod:
    push    {r0, r1, ip, lr}
    bl      __aeabi_idiv
    pop     {r2, r3, ip, lr}
    mul     r12, r0, r3
    sub     r1, r2, r12
    bx      lr

.size __aeabi_idivmod, .- __aeabi_idivmod
