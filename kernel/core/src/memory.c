#include "memory.h"

extern uint32_t _ePSP;
extern uint32_t _bPSP;

uint32_t static const endOfStack = (uint32_t)&_ePSP;
uint32_t static currentStack = endOfStack;
uint32_t static const beginOfStack = (uint32_t)&_bPSP;

MEMORY_STATUS allocateStack(uint32_t stackSize, struct stack_t *processStack){

    if((currentStack - stackSize) < beginOfStack){
        return STACK_UNAVAILABLE;
    } else {
        processStack->stackEnd = currentStack;
        processStack->currentStack = currentStack;
        currentStack-=stackSize;
        processStack->stackBegin = currentStack;
        return MEMORY_SUCCESS;
    }

}