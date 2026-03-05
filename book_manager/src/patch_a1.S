#if defined(W810_R4EA031)
    .equ oncreate_ret, 0x4563E3EC
    .equ onclosebook_func, 0x4563EC38
    .equ tab_focus_ret1, 0x4563E424
    .equ tab_focus_ret2, 0x4563E42A
    .equ def_on_tabswitch, 0x4563E1EC
    .equ TabMenuBar_SetOnTabSwitch, 0x45153ABC
#endif

.section .text.tab_icon_1
.thumb
    .hword 0xE7F0
    .hword 0xE7F1

.section .text.tab_icon_2
.thumb
    .word 0xE7F2
    .word 0xE7F3

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

.section .text.activetask_tab
.thumb
    ldr     r3, =_activetasks+1
    bx      r3

@ Patch function
.section .text.patch_section
.thumb
_tabfocus:
    bl      GetFocusTab
    cmp     r0, #0
    bne     _first_tab
    ldr     r3, =tab_focus_ret1+1
    bx      r3

_first_tab:
    ldr     r3, =tab_focus_ret2+1
    bx      r3

.align 2

_oncreate:
    bl      CreateBookAndElfsLists
    ldr     r1, =def_on_tabswitch+1
    ldr     r0, [r5, #0]
    ldr     r3, =TabMenuBar_SetOnTabSwitch+1
    blx     r3
    ldr     r3, =oncreate_ret+1
    bx      r3

.align 2

_onclose:
    cmp     r4, #0
    beq     _nextonclose
    mov     r0, #0
    ldr     r3, =onclosebook_func+1
    blx     r3
    bl      ActivityBook_onClose
_nextonclose:
    pop     {r1-r7, pc}

.align 2

_events_title:
    push    {lr}
    bl      EventsTitleText
    pop     {pc}

.align 2

_internet:
    mov     r1, #2
    bl      CreateElfMenu
    pop     {r4-r7, pc}

.align 2

_activetasks:
    mov     r1, #1
    bl      CreateBookMenu
    pop     {r4-r7, pc}
