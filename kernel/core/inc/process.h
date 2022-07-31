#ifndef PROCESS_H
#define PROCESS_H

    #include "common.h"
    #include "memory.h"

    #ifdef __ASSEMBLER__
        .global saveContext
        .global retrieveContext
        .global startProcessContext
    #else
        struct process_t {
            uint8_t id;
            struct stack_t stack;
            struct process_t *previous;
            struct process_t *next;
        };

        void configureProcessContext(void );
        void createProcess (uint32_t stackSize, struct process_t *process, voidFunctionPointer handlerFunction, uint8_t handlerSize, voidFunctionPointer function);
        uintptr_t saveContext();
        uintptr_t retrieveContext(uintptr_t currentStack);
        void startProcessContext(void );
    #endif

#endif //PROCESS_H
