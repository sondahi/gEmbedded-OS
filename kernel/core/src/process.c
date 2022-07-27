#include "process.h"
#include "system.h"
#include "core.h"

static struct process_t *currentProcess = 0;

static struct process_t processTest;
extern void test(void );

void createProcess(struct process_t * process, void (* processFunction)(void ), uint32_t stackSize){
    static uint8_t processId = 0;

    MEMORY_STATUS status = allocateStack (stackSize, &process->processStack);
    if(status != MEMORY_SUCCESS){
        //return status;
        return;
    } else{
        process->processId = ++processId;
        process->function = (uintptr_t ) processFunction;
        uintptr_t volatile *stackPointer = (uintptr_t *) process->processStack.currentStack;
        *stackPointer-- = DUMMY_XPSR;
        *stackPointer-- = process->function;
        *stackPointer = EXCEPTION_RETURN;
        for (int i = 0; i <13 ; ++i) {
            * --stackPointer = 0x0;
        }
        process->processStack.currentStack = (uintptr_t ) stackPointer;
    }

    process->next = currentProcess->next;
    currentProcess->next = process;

}

void configureProcessContext(void ){

    createProcess (&processTest,test,1024);


    processTest.next = &processTest;
    processTest.previous = &processTest;
    currentProcess = &processTest;

    setPSP (currentProcess->processStack.currentStack);

}

void startProcess(void ){
    __asm__ volatile ("svc 0");
}

void SVC_Handler(void ){
    if(!ST->STK_CTRL.enable_rw)
        ST->STK_CTRL.enable_rw = HIGH;
}

void SysTick_Handler(void ){
    SCB->ICSR.pendingSVSet_rw = HIGH;
}

void PendSV_Handler(void ){
    currentProcess->processStack.currentStack = saveContext();
    currentProcess = currentProcess->next;
    currentProcess->processStack.currentStack = retrieveContext (currentProcess->processStack.currentStack);
}
