#include "system.h"
#include "exception.h"
#include "time.h"
#include "process.h"

void initSystem(void ){
    initExceptions();
    initProcessContext();
}