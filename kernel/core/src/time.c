#include "system.h"

void SysTick_Handler(void ){
   SCB->ICSR.pendingSVSet_rw = HIGH;
}
