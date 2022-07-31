    .syntax unified
    .cpu    cortex-m4
    .thumb

    #include "process.h"
    #include "systemcall.h"

    .global processHandler

    .section .text
    .type saveContext, %function
saveContext:
    mrs r0, psp
    stmdb r0!, {r4-r11}
    bx lr
    .align FUNCTION

    .section .text
    .type retrieveContext, %function
retrieveContext:
    ldmia r0!, {r4-r11}
    msr psp, r0
    bx lr
    .align FUNCTION

    .section .text
    .type startProcessContext, %function
startProcessContext:
    svc INIT_TIMER
    pop {r0-r12, lr}
    pop {pc}
    .align FUNCTION

    // //till lr everthing is successful
    // now pc must to point init process stack of function pointer which is thumb set#
    //svc 0 // stacking and unstacking in inital proccss stack but does not affect dumy settings +
    //

    // handler prototype. being copied to sram stack to execute process function
    .section .text
    .type processHandler, %function
processHandler:
    ldr	r0, [pc, #4]
    ldr	r1, [r0, #0]
    blx	r0
    svc	1 // loop bitince napcaz kernel moda mi dönmek lazim ? buraya geri dönmemek lazim
    .word	0x00000000 // replacing in stackallocate
    .align FUNCTION