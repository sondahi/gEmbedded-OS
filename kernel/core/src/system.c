#include "exception.h"
#include "process.h"

void initSystem(void ){
    initExceptions();
    initProcessContext();
}