#include "core.h"
#include "system.h"
#include "memory.h"
#include "exception.h"
#include "process.h"

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

static struct process_t process1;
static struct process_t process2;

int volatile pendSV = 0;

void runner1(void ){

    while (1){
        ++pendSV ;
    }

}

void runner2(void ){

    while (1){
        --pendSV;
    }

}

void test(void ){

    //createProcess (&process1,runner1,1024);
    //createProcess (&process2,runner2,1024);

    while (1){
        pendSV+=1;
    }

}



