#include "systemcall.h"
#include "system.h"

void SVC_Handler(void ){
    if(!ST->STK_CTRL.enable_rw){
        ST->STK_CTRL.enable_rw = HIGH;
    }
}