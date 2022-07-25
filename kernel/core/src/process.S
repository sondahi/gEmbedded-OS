    .syntax unified
    .cpu cortex-m4
    .fpu softvfp
    .thumb

    #include "process.h"

    .section .text
    .type saveContext, %function
saveContext:
    mrs r0, psp
    stmdb r0!, {r4-r11}
    bx lr

    .section .text
    .type retrieveContext, %function
retrieveContext:
    ldmia r0!, {r4-r11}
    msr psp, r0
    bx lr