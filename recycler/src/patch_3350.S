#if defined(J108_R7EA011)
    .equ generic_delete_ret, 0x1495DD3C
    .equ mark_delete_ret, 0x1477145A
    .equ directory_delete_ret, 0x149DC940
    .equ file_delete_ret, 0x1447AACE

    .equ GUIObject_SoftKeys_SetAction, 0x1455ADF0
#endif

.section .text.patch_Generic_Delete
.thumb
    ldr r3, =new_generic_delete+1
    bx r3

.section .text.patch_Mark_Delete
.thumb
    ldr r3, =new_mark_delete+1
    bx r3

.section .text.patch_Directory_Delete
.thumb
    ldr r3, =new_directory_delete+1
    bx r3

.section .text.patch_FileDelete
.thumb
    ldr r3, =file_delete+1
    bx r3

.section .text.patch_section
.thumb
new_generic_delete:
    lsl r1, r5, #0
    ldr r3, =GUIObject_SoftKeys_SetAction+1
    blx r3
    mov r2, #0     @ r2 is_marked
    mov r1, #0     @ r1 mode
    ldr r0, [r4, #0x14]
    bl Set_New_SoftKeys
    ldr r0, [r4, #0x14]
    ldr r3, =generic_delete_ret+1
    bx r3

new_mark_delete:
    lsl r1, r7, #0
    ldr r3, =GUIObject_SoftKeys_SetAction+1
    blx r3
    ldr r0, [r5, #0x10]
    mov r2, #1     @ r2 is_marked
    mov r1, #0     @ r1 mode
    ldr r0, [r0, #0x10]
    bl Set_New_SoftKeys
    ldr r3, =mark_delete_ret+1
    bx r3

new_directory_delete:
    ldr r1, =0xFC5
    ldr r0, [r4, #0x14]
    ldr r3, =GUIObject_SoftKeys_SetAction+1
    blx r3
    mov r2, #0     @ r2 is_marked
    mov r1, #1     @ r1 mode
    ldr r0, [r4, #0x14]
    bl Set_New_SoftKeys
    ldr r3, =directory_delete_ret+1
    bx r3

file_delete:
    lsl r0, r4, #0
    mov r2, #0
    add r0, #0xA
    bl New_FileDelete
    ldr r3, =file_delete_ret+1
    bx r3
