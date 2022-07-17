#ifndef MODE_H
#define MODE_H

#include "common.h"

    #define FPU_ACTIVE          (1U<<2)
    #define FPU_NONACTIVE       (0<<2)
    #define MSP_ACTIVE          (0<<1)
    #define PSP_ACTIVE          (1U<<1)
    #define THREAD_PRIVILEGED   (0<<0)
    #define THREAD_UNPRIVILEGED (1U<<0)

    #define SYSTEM_MODE         (FPU_ACTIVE|PSP_ACTIVE|THREAD_PRIVILEGED)
    #define APPLICATION_MODE    (FPU_ACTIVE|PSP_ACTIVE|THREAD_UNPRIVILEGED)


    #ifdef __ASSEMBLER__
        .global setMode
    #else
        void setMode(uint8_t coreMode);
    #endif

#endif //MODE_H
