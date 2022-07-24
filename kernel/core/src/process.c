#include "process.h"
#include "system.h"

static struct process_t *currentProcess = 0;

static struct process_t kernelProcess;
static struct process_t mainProcess;

extern void runner1(void );
extern void runner2(void );

#define DUMMY_XPSR (0x01000000U)

 void initabc(void ){
    volatile uintptr_t *ptr;

    ptr = (uintptr_t *) kernelProcess.processStack.currentPointer;
    ptr--;
    *ptr = DUMMY_XPSR;
    ptr--;
    *ptr = kernelProcess.function; // pc
    ptr--;
    *ptr = 0xFFFFFFFD; // lr
    for (int i = 0; i < 13; ++i) {
        ptr--;
        *ptr = 0x0;
    }
    kernelProcess.processStack.currentPointer = (uintptr_t) ptr;

    ptr = (uintptr_t *) mainProcess.processStack.currentPointer;
    ptr--;
    *ptr = DUMMY_XPSR;
    ptr--;
    *ptr = mainProcess.function; // pc
    ptr--;
    *ptr = 0xFFFFFFFD; // lr
    for (int i = 0; i < 13; ++i) {
        ptr--;
        *ptr = 0x0;
    }
    mainProcess.processStack.currentPointer = (uintptr_t) ptr;
}

void initProcessContext(void ){

    kernelProcess.processId = 1;
    allocateStack (1024, &kernelProcess.processStack);
    kernelProcess.function = (uintptr_t ) runner1;

    mainProcess.processId = 2;
    allocateStack (1024, &mainProcess.processStack);
    mainProcess.function=(uintptr_t ) runner2;

    kernelProcess.previous = &mainProcess;
    kernelProcess.next = &mainProcess;

    mainProcess.previous = &kernelProcess;
    mainProcess.next = &kernelProcess;

    currentProcess = &kernelProcess;

    //initabc();



}

void PendSV_Handler(void ){
    currentProcess = currentProcess->next;
}