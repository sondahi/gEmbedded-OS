#ifndef PROCESS_H
#define PROCESS_H

    #include "common.h"
    #include "memory.h"

    #ifdef __ASSEMBLER__
        .global startProcess
        .global saveContext
        .global retrieveContext
    #else
        struct process_t {
            uint8_t processId;
            uintptr_t function;
            struct stack_t processStack;
            struct process_t *previous;
            struct process_t *next;
        };

        void initProcessContext(void );
        void startProcess(void );
        uintptr_t * saveContext();
        void retrieveContext(uintptr_t * pspValue);
    #endif

#endif //PROCESS_H
