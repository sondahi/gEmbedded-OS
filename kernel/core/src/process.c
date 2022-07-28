#include "process.h"
#include "system.h"
#include "core.h"

static struct process_t *currentProcess = 0;

static struct process_t processTest;
extern void test(void );

void createProcess(struct process_t * process, void (* processFunction)(void ), uint32_t stackSize){
    static uint8_t processId = 0;

    process->processStack.function = (uintptr_t) processFunction;

    MEMORY_STATUS status = allocateStack (stackSize, &process->processStack,((uintptr_t) processHandler)-1);
    if(status != MEMORY_SUCCESS){
        //return status;
        return;
    } else{
        process->processId = ++processId;
        uintptr_t volatile *stackPointer = (uintptr_t *) process->processStack.currentAddress;
        *stackPointer-- = DUMMY_XPSR;
        *stackPointer-- = process->processStack.function;
        *stackPointer = EXCEPTION_RETURN;
        for (int i = 12; i >=0 ; --i) {
            --stackPointer;
            * stackPointer = i;
        }
        process->processStack.currentAddress = ((uintptr_t ) stackPointer);
    }

    process->next = currentProcess->next;
    currentProcess->next = process;

}

void configureProcessContext(void ){

    createProcess (&processTest,test,1024);

    processTest.next = &processTest;
    processTest.previous = &processTest;
    currentProcess = &processTest;

    setPSP (currentProcess->processStack.currentAddress);

}

void SVC_Handler(void ){
    if(!ST->STK_CTRL.enable_rw){
        ST->STK_CTRL.enable_rw = HIGH;
    }
}

void SysTick_Handler(void ){
    SCB->ICSR.pendingSVSet_rw = HIGH;
}

void PendSV_Handler(void ){
    currentProcess->processStack.currentAddress = saveContext();
    currentProcess = currentProcess->next;
    currentProcess->processStack.currentAddress = retrieveContext (currentProcess->processStack.currentAddress);
}
