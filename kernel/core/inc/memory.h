#ifndef MEMORY_H
#define MEMORY_H

    #include "common.h"

    #ifdef __ASSEMBLER__
        #define BSS_DEFAULT_VALUE (0x00U)

        .global memoryCopy
        .global memoryFill
    #else

        struct stack_t{
            uintptr_t stackBegin;
            uintptr_t currentPointer;
            uintptr_t stackEnd;
        };

        void memoryCopy(uintptr_t *sourceAddress, uintptr_t *destinationAddress, uint32_t blockSize);
        void memoryFill(uintptr_t *sourceAddress, uint32_t blockSize, uint32_t value);
        void allocateStack(uint32_t stackSize, struct stack_t *processStack);
    #endif

#endif //MEMORY_H
