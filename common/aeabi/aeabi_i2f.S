/*
 * __aeabi_i2f.S
 */

.syntax unified
.section .text.patch_section
.arm
.global __aeabi_i2f
.type __aeabi_i2f, %function
.align 4

__aeabi_i2f:
    cmp r0, #0
    beq zero
    mov r1, r0
    mov r2, #0 @ sign
    cmp r1, #0
    bge positive
    rsb r1, r1, #0
    mov r2, #1

positive:
    clz r3, r1
    rsb r3, r3, #31 @ exponent
    mov r1, r1, lsl r3
    mov r1, r1, lsr#8
    add r3, r3, #127
    mov r3, r3, lsl#23
    mov r2, r2, lsl#31
    orr r0, r1, r3
    orr r0, r0, r2
    bx lr

zero:
    mov r0, #0
    bx lr

.size __aeabi_i2f, .- __aeabi_i2f
