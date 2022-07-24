#ifndef PROCESS_H
#define PROCESS_H

    #include "common.h"
    #include "memory.h"

    struct process_t {
        uint8_t processId;
        uintptr_t function;
        struct stack_t processStack;
        struct process_t *previous;
        struct process_t *next;
    };

    void initProcessContext(void );

#endif //PROCESS_H
