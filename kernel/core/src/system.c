#include "system.h"

void systemInit(void ){
    SCB->SHCSR.memFaultEna = ENABLE;
    SCB->SHCSR.busFaultEna = ENABLE;
    SCB->SHCSR.usgFaultEna = ENABLE;
}