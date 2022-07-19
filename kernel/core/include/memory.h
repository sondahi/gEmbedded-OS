#ifndef MEMORY_H
#define MEMORY_H

    #include "common.h"

    #ifdef __ASSEMBLER__
        #define BSS_DEFAULT_VALUE (0x00U)

        .global memoryCopy
        .global memoryFill
    #else
        void memoryCopy(uint32_t sourceAddress, uint32_t destinationAddress, uint32_t blockSize);
    #endif

#endif //MEMORY_H
