    .syntax unified
    .cpu cortex-m4
    .thumb

    #include "mode.h"

    .section .text
    .type setMode, %function
setMode:
    msr control, r0
    bx lr

    .end