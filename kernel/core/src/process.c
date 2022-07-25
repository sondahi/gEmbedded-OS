#include "process.h"
#include "system.h"

static struct process_t *currentProcess = 0;

static struct process_t runnerTestProcess;
static struct process_t runnerProcess1;
static struct process_t runnerProcess2;

extern void test(void );
extern void runner1(void );
extern void runner2(void );

#define DUMMY_XPSR (0x01000000U)

void initProcessContext(void ){

    runnerTestProcess.processId = 0;
    allocateStack (1024, &runnerTestProcess.processStack);
    runnerTestProcess.function = (uintptr_t ) test;
    runnerTestProcess.processStack.currentPointer--;
    * runnerTestProcess.processStack.currentPointer-- = DUMMY_XPSR;
    * runnerTestProcess.processStack.currentPointer-- = runnerTestProcess.function;
    * runnerTestProcess.processStack.currentPointer = 0xFFFFFFFD;
    for (int i = 0; i <13 ; ++i) {
        runnerTestProcess.processStack.currentPointer--;
        * runnerTestProcess.processStack.currentPointer = 0x0;
    }

    runnerProcess1.processId = 1;
    allocateStack (1024, &runnerProcess1.processStack);
    runnerProcess1.function = (uintptr_t ) runner1;
    runnerProcess1.processStack.currentPointer--;
    * runnerProcess1.processStack.currentPointer-- = DUMMY_XPSR;
    * runnerProcess1.processStack.currentPointer-- = runnerProcess1.function;
    * runnerProcess1.processStack.currentPointer = 0xFFFFFFFD;
    for (int i = 0; i <13 ; ++i) {
        runnerProcess1.processStack.currentPointer--;
        * runnerProcess1.processStack.currentPointer = 0x0;
    }

    runnerProcess2.processId = 2;
    allocateStack (1024, &runnerProcess2.processStack);
    runnerProcess2.function=(uintptr_t ) runner2;
    runnerProcess2.processStack.currentPointer--;
    * runnerProcess2.processStack.currentPointer-- = DUMMY_XPSR;
    * runnerProcess2.processStack.currentPointer-- = runnerProcess2.function;
    * runnerProcess2.processStack.currentPointer = 0xFFFFFFFD;
    for (int i = 0; i <13 ; ++i) {
        runnerProcess2.processStack.currentPointer--;
        * runnerProcess2.processStack.currentPointer = 0x0;
    }

    runnerTestProcess.previous = &runnerProcess2;
    runnerTestProcess.next = &runnerProcess1;

    runnerProcess1.previous = &runnerTestProcess;
    runnerProcess1.next = &runnerProcess2;

    runnerProcess2.previous = &runnerProcess1;
    runnerProcess2.next = &runnerTestProcess;


    currentProcess = &runnerTestProcess;

}

void startProcess(void ){
    __asm__ volatile ("svc 0");
}

void SVC_Handler(void ){
    ST->STK_CTRL.enable_rw = HIGH;
}

void SysTick_Handler(void ){
    SCB->ICSR.pendingSVSet_rw = HIGH;
}

void PendSV_Handler(void ){
    currentProcess->processStack.currentPointer = saveContext();
    currentProcess = currentProcess->next;
    retrieveContext (currentProcess->processStack.currentPointer);
}

