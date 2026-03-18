#if defined(C510_R1HA035)
    .equ SK_TEXT, 0
#elif defined(W760_R3EM001)
    .equ SK_TEXT, 0x2C82
#elif defined(W810_R4EA031)
    .equ SK_TEXT, 0x6D9
#endif

.section .text.standby_sk_text
    .word SK_TEXT

.section .text.standby_sk_link
    .word GotoShortcut
