#include "process.h"
#include "system.h"
#include "core.h"
#include "exception.h"

extern void main(void );
extern void processHandler(void );

static struct process_t processMain;
static struct process_t *currentProcess = 0;

void createProcess(uint32_t stackSize, struct process_t *process, voidFunctionPointer handlerFunction, uint8_t handlerSize, voidFunctionPointer function){
    static uint8_t currentId = 0;

    process->stack.size = stackSize;
    process->stack.handlerAddress = (uint32_t) handlerFunction;
    process->stack.handlerSize = handlerSize;
    process->stack.functionAddress = (uint32_t) function;

    MEMORY_STATUS status = allocateStack (&process->stack); // size must be dynamic
    if(status != MEMORY_SUCCESS){
        //return status;
        return;
    } else{
        process->id = ++currentId;
    }

    process->next = currentProcess->next;
    currentProcess->next = process;

}

void configureProcessContext(void ){

    createProcess (1024,&processMain,&processHandler,12,&main);

    processMain.next = &processMain;
    processMain.previous = &processMain;
    currentProcess = &processMain;

    setPSP ((uint32_t) currentProcess->stack.current);

}

void SysTick_Handler(void ){
    SCB->ICSR.pendingSVSet_rw = HIGH;
}

void PendSV_Handler(void ){
    currentProcess->stack.current = (uintptr_t *) saveContext ();
    currentProcess = currentProcess->next;
    currentProcess->stack.current = (uintptr_t *) retrieveContext ((uintptr_t) currentProcess->stack.current);
}
