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
static struct process_t process3;
static struct process_t process4;

extern void processHandler(void );

int volatile sharedData;
int volatile mainData;

void runner1(void ){

    uint32_t volatile runner1Data;

    while (1){
        ++sharedData;
    }

}

void runner2(void ){

    uint32_t volatile runner2Data;

    while (1){
        --sharedData;
    }

}

void main(void ){

    createProcess (1024,&process1,&processHandler,12,&runner1);

    createProcess (1024,&process2,&processHandler,12,&runner2);

    //createProcess (&process3,runner1,1024);
    //createProcess (&process4,runner2,1024);

    while (1){
        sharedData=0;
    }
    //sharedData++;

}



