#if defined(C510_R1HA035)
    .equ j_TextID_CreateIntegerID, 0x141ADFAC
#elif defined(W760_R3EM001)
    .equ j_TextID_CreateIntegerID, 0x10E5A68E
#endif

.section .text.patch_ChangeBrightness_Enter
.thumb
    .word New_Brightness_ChangeBrightness

.section .text.patch_ChangeBrightness_Exit
    .word 0

.section .text.patch_fix_secondline
.thumb
    mov     r2, #0
    add     r1, r2, #0
    b       j_TextID_CreateIntegerID

.section .text.patch_brightness_1
.thumb
    cmp     r2, #1

.section .text.patch_brightness_2
.thumb
    mov     r2, #1
