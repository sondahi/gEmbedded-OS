    .syntax unified
    .cpu    cortex-m4
    .fpu softvfp
    .thumb

    #include "memory.h"

    .section .text
    .type memoryCopy, %function
memoryCopy:
     cbz r2, memoryCopyExit
     sub r2, r2, #0x04
     ldr r3, [r0,r2]
     str r3, [r1,r2]
     b memoryCopy
     memoryCopyExit:
        bx lr

    .section .text
    .type memoryFill, %function
memoryFill:
     cbz r1, memoryFillExit
     sub r1, r1, #0x04
     str r2, [r0,r1]
     b memoryFill
     memoryFillExit:
        bx lr