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

int pendSV = 0;


void runner1(void ){

    while (1){
        ++pendSV;
    }

}

void runner2(void ){
    while (1){
        --pendSV;
    }

}

void test(void ){

    __asm__ volatile ("svc #0");

}
