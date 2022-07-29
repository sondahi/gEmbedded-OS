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
    nop

    .section .text
    .type retrieveContext, %function
retrieveContext:
    ldmia r0!, {r4-r11}
    msr psp, r0
    bx lr
    nop

    .section .text
    .type startProcess, %function
startProcess:
    svc 0 // stacking and unstacking in inital proccss stack but does not affect dumy settings +
    pop {r0-r12, lr} //till lr everthing is successful
    // now pc must to point init process stack of function pointer which is thumb set
    pop {pc}
    // default status
    //bx r0
    nop
    nop

    .section .text
    .type processHandler, %function
processHandler:
    ldr	r0, [pc, #4]
    ldr	r1, [r0, #0]
    blx	r0
    svc	1 // loop bitince napcaz kernel moda mi dönmek lazim ? buraya geri dönmemek lazim
    .word	0x00000000