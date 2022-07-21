#include "system.h"
#include "exception.h"

void initFaults(void ){
    SCB->SHCSR.usgFaultEna_rw = HIGH;
    SCB->SHCSR.busFaultEna_rw = HIGH;
    SCB->SHCSR.memFaultEna_rw = HIGH;
}
