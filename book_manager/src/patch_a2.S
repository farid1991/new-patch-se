#if defined(C510_R1HA035)
    .equ NEW_ICON1, 0x834
    .equ NEW_ICON2, 0x82E
    .equ NEW_TEXT1, 0xCFB
    .equ GUI_PTR, 0x24
    .equ oncreate_ret, 0x14E057B8
    .equ onclosebook_func, 0x14D5F2E8
    .equ tab_focus_ret, 0x14E05990
    .equ tab_focus_func, 0x14E05828
    .equ get_focus_ret, 0x14E059AE
    .equ def_on_tabswitch, 0x140250A0
    .equ rsstickerbook_onclose, 0x156CBC70
    .equ TabMenuBar_SetOnTabSwitch, 0x14041F44
#elif defined(W760_R3EM001)
    .equ NEW_ICON1, 0xF3E6
    .equ NEW_ICON2, 0xF3E1
    .equ NEW_TEXT1, 0xDC9
    .equ GUI_PTR, 0x24
    .equ oncreate_ret, 0x10BD076C
    .equ onclosebook_ret, 0x10BD03D8
    .equ onclosebook_func, 0x10BD008C
    .equ tab_focus_ret, 0x10BD0504
    .equ tab_focus_func, 0x10BD00B0
    .equ get_focus_ret, 0x10BD0522
    .equ def_on_tabswitch, 0x10BD072C
    .equ rsstickerbook_onclose, 0x117AE6C8
    .equ TabMenuBar_SetOnTabSwitch, 0x1180EA44

#endif

.section .text.tab_icon_1
.thumb
    ldr     r7, =_iconinternet+1
    bx      r7

.section .text.tab_icon_2
.thumb
    .word NEW_ICON2

.section .text.tab_focus
.thumb
    ldr     r3, =_tabfocus+1
    bx      r3

.section .text.gui_create
.thumb
    ldr     r3, =_oncreate+1
    bx      r3

.section .text.book_close
.thumb
    ldr     r3, =_onclose+1
    bx      r3

.section .text.title_events
.thumb
    ldr     r3, =_events_title+1
    bx      r3

.section .text.internet_tab
.thumb
    ldr     r3, =_internet+1
    bx      r3

.section .text.shortcuts_tab
.thumb
    ldr     r3, =_shortcurts+1
    bx      r3

.section .text.activetask_tab
.thumb
    ldr     r3, =_activetasks+1
    bx      r3

@ Patch function
.section .text.patch_section
.thumb
_iconinternet:
#if defined(DB3150v1)
    str     r3, [r0, #4]
#endif
    ldr     r1, =NEW_ICON1
    strh    r1, [r0, #8]
    sub     r1, r1, #1
    strh    r1, [r0, #0xA]
    ldr     r1, =NEW_TEXT1
    str     r1, [r0, #0xC]
    pop     {r4, r5, pc}

.align 2

_tabfocus:
    ldr     r3, =tab_focus_func+1
    blx     r3
    cmp     r0, #0
    beq     _get_focus
    ldr     r3, =tab_focus_ret+1
    bx      r3
_get_focus:
    bl      GetFocusTab
    add     r5, r0, #0
    ldr     r3, =get_focus_ret+1
    bx      r3

.align 2

_oncreate:
#if defined(DB3150v1)
    mov     r1, #9
    ldr     r3, =GUIObject_SetStyle+1
    blx     r3
#endif
    bl      CreateBookAndElfsLists
    ldr     r1, =def_on_tabswitch+1
    ldr     r0, [r4, #GUI_PTR]
    ldr     r3, =TabMenuBar_SetOnTabSwitch+1
    blx     r3
    ldr     r3, =oncreate_ret+1
    bx      r3

.align 2

_onclose:
#if defined(DB3150v1)
    ldr     r3, =onclosebook_func+1
    blx     r3
    bl      ActivityBook_onClose
    pop     {r4-r7, pc}
#elif defined(DB3150v2)
    add     r0, r4, #0
    ldr     r3, =onclosebook_func+1
    blx     r3
    cmp     r5, #0
    beq     _exit
    mov     r0, #2
    ldr     r3, =onclosebook_ret+1
    blx     r3
_exit:
    bl      ActivityBook_onClose
    pop     {r4-r7, pc}
#elif defined(DB3150v1) || defined(DB3200) || defined (DB3210)
    bl      ActivityBook_onClose
    mov     r0, r4
    ldr     r3, =onclosebook_func+1
    blx     r3
    pop     {r4-r5, pc}
#endif

.align 2

_events_title:
    push    {lr}
    bl      EventsTitleText
    pop     {pc}

.align 2

_internet:
    add     r1, r5, #0
    add     r0, r4, #0
    bl      CreateShortcutMenu
    pop     {r4-r6, pc}

.align 2

_shortcurts:
    add     r1, r5, #0
    add     r0, r4, #0
    bl      CreateElfMenu
    pop     {r4-r6, pc}

.align 2

_activetasks:
    add     r1, r5, #0
    add     r0, r4, #0
    bl      CreateBookMenu
    pop     {r4-r6, pc}

.section .text.patch_section
.thumb
.global isrsstickerbook
.type isrsstickerbook, %function
isrsstickerbook:
    ldr     r1, =rsstickerbook_onclose+1
    ldr     r0, [r0, #4]
    cmp     r0, r1
    bne     notequal
    mov     r0, #1
    bx      lr
notequal:
    mov     r0, #0
    bx      lr
