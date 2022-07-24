#include "system.h"
#include "userinterface.h"

void SVC_Handler(void ){
    int static volatile enabled = 0;
    if (!enabled){
        ST->STK_CTRL.enable_rw = HIGH;
        enabled = 1;
    }
}

void startProcess(void ){
    __asm__ volatile ("svc 0");
}
