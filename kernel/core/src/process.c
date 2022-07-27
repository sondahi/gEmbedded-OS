#include "process.h"
#include "system.h"

static struct process_t *currentProcess = 0;

static struct process_t processTest;
static struct process_t process1;
static struct process_t process2;

extern void test(void );
extern void runner1(void );
extern void runner2(void );


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
        stackPointer--;
        *stackPointer-- = DUMMY_XPSR;
        *stackPointer-- = process->function;
        *stackPointer = EXCEPTION_RETURN;
        for (int i = 0; i <13 ; ++i) {
            stackPointer--;
            * stackPointer = 0x0;
        }
        process->processStack.currentStack = (uintptr_t ) stackPointer;
    }

}

void configureProcessContext(void ){

    createProcess (&processTest,test,1024);
    createProcess (&process1,runner1,1024);
    createProcess (&process2,runner2,1024);

    processTest.next = &process1;
    process1.next = &process2;
    process2.next = &processTest;
    currentProcess = &processTest;

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
