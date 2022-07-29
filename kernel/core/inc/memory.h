#ifndef MEMORY_H
#define MEMORY_H

    #include "common.h"

    #define END_OF_MSP          (0X20020000U)
    #define LENGTH_OF_MSP       ((1U)*(1024U))
    #define BEGIN_OF_MSP        ((END_OF_MSP)-(LENGTH_OF_MSP))
    #define END_OF_PSP          ((BEGIN_OF_MSP) - (4U))
    #define LENGTH_OF_PSP       ((27U)*(1024U))
    #define BEGIN_OF_PSP        ((END_OF_PSP)-(LENGTH_OF_PSP))

    #ifdef __ASSEMBLER__
        #define BSS_DEFAULT_VALUE (0x00U)

        .global memoryCopy
        .global memoryFill
    #else
        typedef enum MEMORY_STATUS_t{
            MEMORY_SUCCESS = 0,
            STACK_UNAVAILABLE = 1,
            HEAP_UNAVAILABLE = 2
        } MEMORY_STATUS;

        struct stack_t{
            uintptr_t begin;
            uintptr_t handler;
            uintptr_t currentAddress;
            uintptr_t end;
        };

        void memoryCopy(uintptr_t sourceAddress, uintptr_t destinationAddress, uint32_t blockSize);
        void memoryFill(uintptr_t destinationAddress, uint32_t blockSize, uint32_t value);
        MEMORY_STATUS allocateStack(uint32_t stackSize, struct stack_t *processStack, uintptr_t processFunction, uintptr_t handlerAddress, uint32_t handlerSize);
    #endif

#endif //MEMORY_H
