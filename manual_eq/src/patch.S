#if defined(J108_R7EA011)
    .equ exit_set_eq_hook, 0x14797A86
    .equ add_softkeys_ret, 0x14A07680

    .equ MusicApplication_EnableEqualizer, 0x14797EEC
    .equ MusicApplication_SetEqualizerGain, 0x14797DE0
    .equ GUIObject_SoftKeys_SetItemAsSubItem, 0x14559478
#endif

.section .text.patch_fix_set_eq_hook1
.thumb
    beq     exit_set_eq_hook

.section .text.patch_fix_set_eq_hook2
.thumb
    beq     exit_set_eq_hook

.section .text.patch_set_eq_hook
.thumb
    ldr     r3, =set_equalizer+1
    bx      r3

.section .text.patch_eq_softkeys
.thumb
    ldr     r3, =add_softkeys+1
    bx      r3

.section .text.patch_eq_set_gain
.thumb
    push    {lr}
    ldr     r3, =new_setequalizergain+1
    blx     r3
    pop     {pc}

.section .text.patch_section
.thumb
set_equalizer:
    bl      SetEqualizerState
    lsl     r0, r4, #0
    bl      new_setequalizergain
    pop     {r4-r6, pc}

.align 2

new_setequalizergain:
    push    {r4, lr}
    add     r4, r0, #0
    cmp     r0, #0
    beq     exit_eq_gain
    add     r0, r4, #0
    ldr     r3, =MusicApplication_EnableEqualizer+1
    blx     r3
    bl      GetEqualizerState
    cmp     r0, #0
    beq     eq_preset
    add     r0, r4, #0
    bl      SetManualEQ
    b       exit_eq_gain

eq_preset:
    add     r1, r4, #0
    add     r1, #0x70
    add     r0, r4, #0
    ldr     r3, =MusicApplication_SetEqualizerGain+1
    blx     r3
exit_eq_gain:
    pop     {r4, pc}

.align 2
add_softkeys:
#ifdef J20_R7CA064
    ldr     r0, [r4, #0x20]
#endif
    bl      create_new_softkeys
    ldr     r0, [r4, #0x20]
    mov     r2, #0xA
    mov     r1, #0x8
    ldr     r3, =GUIObject_SoftKeys_SetItemAsSubItem+1
    blx     r3
    ldr     r3, =add_softkeys_ret+1
    bx      r3
