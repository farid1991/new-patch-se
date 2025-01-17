#ifdef K800_R8BF003
    .equ gui_settitletype, 0x45464344+1
    .equ gui_msg, 0x45484AE0+1
    .equ patch_RET, 0x45484C98+1
#endif

    // MainMenu hook
    .section .text.scrollbar_hook
    .thumb
    ldr     r3, =patch_scrollbar+1
    bx      r3

    // Patch function
    .section .text.patch_section
    .thumb
patch_scrollbar:
	add	    r0, r4, #0
	ldr	    r3, =gui_settitletype
	blx	    r3
	mov	    r1, #0
	add	    r0, r4, #0
	bl	    GUIObject_SetScrollbarMode
	ldr	    r1, =gui_msg
	ldr	    r3, =patch_RET
	bx	    r3
