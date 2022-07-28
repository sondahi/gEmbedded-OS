    .syntax unified
    .cpu    cortex-m4
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

    .section .text
    .type startProcess, %function
startProcess:
    svc 0
    ldr r0, = 0x2001fbb8
    bl retrieveContext
    nop
    bx lr

    .section .text
    .type processHandler, %function
processHandler:
    ldr r0, = 0x08000535
    blx r0