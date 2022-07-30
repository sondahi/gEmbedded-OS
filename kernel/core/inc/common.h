#ifndef COMMON_H
#define COMMON_H

    #define HIGH    (0X01U)
    #define LOW     (0x00U)

    #ifdef __ASSEMBLER__
        .equ FUNCTION, 2
        .equ DATA, 4
    #else
        #include <stdint.h>
    #endif

#endif //COMMON_H
