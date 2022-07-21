#ifndef SYSTEM_H
#define SYSTEM_H

    #include "common.h"

    struct CPUID_t {
        uintptr_t revision_r        : 4;
        uintptr_t partNo_r          : 12;
        uintptr_t constant_r        : 4;
        uintptr_t variant_r         : 4;
        uintptr_t implementer_r     : 8;
    };

    struct ICSR_t {
        uintptr_t vectorActivate_rw : 9;
        uintptr_t                   : 2;
        uintptr_t returnToBase_r    : 1;
        uintptr_t vectorPending_r   : 7;
        uintptr_t                   : 3;
        uintptr_t isrPending_r      : 1;
        uintptr_t                   : 2;
        uintptr_t pendingSTClear_w  : 1;
        uintptr_t pendingSTSet_rw   : 1;
        uintptr_t pendingSVClear_w  : 1;
        uintptr_t pendingSVSet_rw   : 1;
        uintptr_t                   : 2;
        uintptr_t nmiPendingSet_rw  : 1;
    };

     struct SHCSR_t{
        uintptr_t memFaultAct_rw    : 1;
        uintptr_t busFaultAct_rw    : 1;
        uintptr_t                   : 1;
        uintptr_t usgFaultAct_rw    : 1;
        uintptr_t                   : 3;
        uintptr_t svCallAct_rw      : 1;
        uintptr_t monitorAct_rw     : 1;
        uintptr_t                   : 1;
        uintptr_t pendSvAct_rw      : 1;
        uintptr_t sysTickAct_rw     : 1;
        uintptr_t usgFaultPended_rw : 1;
        uintptr_t memFaultPended_rw : 1;
        uintptr_t busFaultPended_rw : 1;
        uintptr_t svCallPended_rw   : 1;
        uintptr_t memFaultEna_rw    : 1;
        uintptr_t busFaultEna_rw    : 1;
        uintptr_t usgFaultEna_rw    : 1;
        uintptr_t                   : 13;
    };

     struct SCB_t{
        struct CPUID_t CPUID;
        struct ICSR_t ICSR;
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

    #define SCB ((volatile struct SCB_t *)  (0xE000ED00))

#endif //SYSTEM_H
