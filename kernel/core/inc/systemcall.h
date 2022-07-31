#ifndef SYSTEMCALL_H
#define SYSTEMCALL_H

    #include "common.h"

    #define INIT_TIMER (0X00U)
    #define KILL_PROCESS (0X01U)

    #ifdef __ASSEMBLER__
        .global startProcess
    #else

    #endif

#endif //SYSTEMCALL_H
