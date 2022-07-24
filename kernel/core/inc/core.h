#ifndef CORE_H
#define CORE_H

    #include "common.h"

    #define FPU_ACTIVE          (1U<<2)
    #define FPU_NONACTIVE       (0<<2)
    #define MSP_ACTIVE          (0<<1)
    #define PSP_ACTIVE          (1U<<1)
    #define THREAD_PRIVILEGED   (0<<0)
    #define THREAD_UNPRIVILEGED (1U<<0)

    #define SYSTEM_MODE         (FPU_ACTIVE|PSP_ACTIVE|THREAD_PRIVILEGED)
    #define USER_MODE           (FPU_ACTIVE|PSP_ACTIVE|THREAD_UNPRIVILEGED)


    #ifdef __ASSEMBLER__
        .global setMode
        .global setMSP
        .global setPSP
    #else
        void setMode(uint8_t coreMode);
        void setMSP(uint32_t mspAddress);
        void setPSP(uint32_t pspAddress);
    #endif

#endif //CORE_H
