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

        #define DUMMY_XPSR          (0x01000000U)
        #define EXCEPTION_RETURN    (0xFFFFFFFDU)

        void configureProcessContext(void );
        void createProcess (struct process_t *,void (* processFunction)(void ), uint32_t stackSize);
        void startProcess(void );
        uintptr_t saveContext();
        uintptr_t retrieveContext(uintptr_t currentStack);
    #endif

#endif //PROCESS_H
