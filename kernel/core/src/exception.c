#include "system.h"
#include "exception.h"

void NMI_Handler(void ){
    while (1);
}
void HardFault_Handler(void ){
    while (1);
}
void  MemManage_Handler (void ){
    while (1);
}
void  BusFault_Handler(void ){
    while (1);
}
void  UsageFault_Handler(void ){
    while (1);
}

void initExceptions(void ){
    SCB->SHCSR.usgFaultEna_rw = HIGH;
    SCB->SHCSR.busFaultEna_rw = HIGH;
    SCB->SHCSR.memFaultEna_rw = HIGH;

    SCB->SHPR3.pendSV_rw = PRIORITY_3;
    SCB->SHPR2.svcCall_rw = PRIORITY_2;
    SCB->SHPR3.sysTick_rw = PRIORITY_1;

    ST->STK_VAL.currentValue_rw = 0x00;
    ST->STK_LOAD.reloadValue_rw = DEFAULT_PROCESS_SWITCH;

    ST->STK_CTRL.clockSource_rw = CLOCK_SOURCE_AHB;
    ST->STK_CTRL.tickInt_rw = HIGH;
}
