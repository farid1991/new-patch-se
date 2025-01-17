#if defined(J20_R7CA064)
    .equ STACK_SIZE, 0x24
#elif defined(J108_R7EA011)
    .equ STACK_SIZE, 0x24
#elif defined(U10_R7AA071)
    .equ STACK_SIZE, 0x1C
#elif defined(U100_R7AA076)
    .equ STACK_SIZE, 0x1C
#endif

    // New MainInput key
    .section .text.new_button
    .thumb
    ldr     r3, =new_key+1
    bx      r3

    .section .text.patch_section
    .thumb
new_key:
    cmp     r6, #1
    bne     exit
    bl      CreateShutdownMenu

exit:
	add     sp, #STACK_SIZE
    pop     {r4-r7,pc}