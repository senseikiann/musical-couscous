.syntax unified
.cpu cortex-m3
.thumb

.global _estack
_estack = 0x20005000

.section .isr_vector,"a",%progbits
.word _estack
.word Reset_Handler

.section .text
.thumb_func
.global Reset_Handler

Reset_Handler:
    bl main
    b .
