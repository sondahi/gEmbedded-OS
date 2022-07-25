#include "memory.h"

extern uint32_t _ePSP;
extern uint32_t _bPSP;

uint32_t static const endOfUserStack = (uint32_t)&_ePSP;
uint32_t static userStackPointer = endOfUserStack;
uint32_t static const beginOfUserStack = (uint32_t)&_bPSP;

void allocateStack(uint32_t stackSize, struct stack_t *processStack){
    // total stack kontrol if begine throw exception

    processStack->stackEnd = userStackPointer;
    processStack->currentPointer = (uintptr_t *) processStack->stackEnd;
    userStackPointer-=stackSize;
    processStack->stackBegin = userStackPointer;

}