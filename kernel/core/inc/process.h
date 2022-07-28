#ifndef PROCESS_H
#define PROCESS_H

    #include "common.h"
    #include "memory.h"

    #ifdef __ASSEMBLER__
        .global startProcess
        .global saveContext
        .global retrieveContext
        .global startProcess
        .global processHandler
    #else
        struct process_t {
            uint8_t processId;
            struct stack_t processStack;
            struct process_t *previous;
            struct process_t *next;
        };

        #define DUMMY_XPSR          (0x01000000U)
        #define EXCEPTION_RETURN    (0xFFFFFFFDU)

        void configureProcessContext(void );
        void createProcess (struct process_t *,void (* processFunction)(void ), uint32_t stackSize);
        uintptr_t saveContext();
        uintptr_t retrieveContext(uintptr_t currentStack);
        void startProcess(void );
        void processHandler(void );
    #endif

#endif //PROCESS_H
