#include "core.h"
#include "system.h"
#include "memory.h"
#include "exception.h"

// dataCopy
int dataInt = 1;
char dataChar1 = 2;
short dataShort = 3;
char dataChar2 = 4;

// bssFill
int bssInt;
char bssChar1;
short bssShort;
char bssChar2;

void testBusFaultException(void );

void test(void ){

    testBusFaultException();

}

void testBusFaultException(){
    SCB->SHCSR.memFaultEna = DISABLE;
}