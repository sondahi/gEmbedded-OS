#include "system.h"
#include "exception.h"
#include "time.h"

void systemInit(void ){
    initFaults();
    initSystemTimer();
}