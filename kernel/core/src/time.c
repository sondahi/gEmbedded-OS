#include "system.h"
#include "time.h"

void initSystemTimer(void ){
    ST->STK_CTRL.clockSource_rw = CLOCK_SOURCE_AHB;
    ST->STK_LOAD.reloadValue_rw = DEFAULT_PROCESS_SWITCH;
    ST->STK_VAL.currentValue_rw &= 0x0;
    ST->STK_CTRL.tickInt_rw = HIGH;
    ST->STK_CTRL.enable_rw = HIGH;
}

void SysTick_Handler(void ){
    SCB->ICSR.pendingSVSet_rw = HIGH;
}
