#include "exception.h"
#include "process.h"

void configureSystem(void ){
    configureExceptions();
    configureProcessContext();
}