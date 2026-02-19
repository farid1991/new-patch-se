#if defined(C510_R1HA035)
    .equ title_1_ret, 0x14EA691A+1
    .equ title_2_ret, 0x14EA6648+1
#endif

.section .text.title_1
.thumb
    ldr     r3, =set_title_1+1
    bx      r3

.section .text.title_2
.thumb
    ldr     r3, =set_title_2+1
    bx      r3

@ Patch function
.section .text.patch_section
.thumb
set_title_1:
    mov     r1, r6
    bl      SetTitleText
    ldr     r3, =title_1_ret
    bx      r3

.align 2

set_title_2:
    mov     r1, r6
    bl      SetTitleText
    ldr     r3, =title_2_ret
    bx      r3
