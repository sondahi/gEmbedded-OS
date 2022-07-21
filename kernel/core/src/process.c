#include "process.h"

int pendSV = 0;

void PendSV_Handler(void ){
    pendSV++;
}