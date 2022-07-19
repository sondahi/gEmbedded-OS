#include "exception.h"

// Default_Handler inc 1
int dHand;
int hFHand;

static void hang(){
    while (1);
}

void NMI_Handler(void ) {
    hang ();
}
void HardFault_Handler(void ){
    hFHand = 1;
    hang();
}


void MemManage_Handler(void ){
    hang();
}

void BusFault_Handler(void ){
    hang();
}

void UsageFault_Handler(void ){
    hang();
}

void SVC_Handler(void ){
    hang();
}

void DebugMon_Handler(void ){
    hang();
}

void PendSV_Handler(void ){
    hang();
}

void SysTick_Handler(void ){
    hang();
}
