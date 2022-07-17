#ifndef SYSTEM_H
#define SYSTEM_H

    #include "common.h"

     struct CPUID_t {
        uintptr_t revision      : 4;
        uintptr_t partNo        : 12;
        uintptr_t constant      : 4;
        uintptr_t variant       : 4;
        uintptr_t implementer   : 8;
    };

     struct SHCSR_t{
        uintptr_t memFaultAct      : 1;
        uintptr_t busFaultAct      : 1;
        uintptr_t                  : 1;
        uintptr_t usgFaultAct      : 1;
        uintptr_t                  : 3;
        uintptr_t svCallAct        : 1;
        uintptr_t monitorAct       : 1;
        uintptr_t                  : 1;
        uintptr_t pendSvAct        : 1;
        uintptr_t sysTickAct       : 1;
        uintptr_t usgFaultPended   : 1;
        uintptr_t memFaultPended   : 1;
        uintptr_t busFaultPended   : 1;
        uintptr_t svCallPended     : 1;
        uintptr_t memFaultEna      : 1;
        uintptr_t busFaultEna      : 1;
        uintptr_t usgFaultEna      : 1;
        uintptr_t                  : 13;
    };

     struct SCB_t{
        struct CPUID_t CPUID;
        uintptr_t ICSR;
        uintptr_t VTOR;
        uintptr_t AIRCR;
        uintptr_t SCR;
        uintptr_t CCR;
        uintptr_t SHPR1;
        uintptr_t SHPR2;
        uintptr_t SHPR3;
        struct SHCSR_t SHCSR;
        uintptr_t CFSR;
        uintptr_t MMSR;
        uintptr_t BFSR;
        uintptr_t UFSR;
        uintptr_t HFSR;
        uintptr_t MMAR;
        uintptr_t BFAR;
        uintptr_t AFSR;
    };

    #define ENABLE  (0X01U)
    #define DISABLE (0)
    #define ENABLED (0X01U)
    #define DISABLED (0)

    #define SCB ((volatile struct SCB_t *) (0xE000ED00))


#endif //SYSTEM_H
