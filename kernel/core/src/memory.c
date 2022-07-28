#include "memory.h"

extern uint32_t _ePSP;
extern uint32_t _bPSP;

uint32_t static const endOfStack = (uint32_t)&_ePSP;
uint32_t static currentFrame = endOfStack;
uint32_t static const beginOfStack = (uint32_t)&_bPSP;

MEMORY_STATUS allocateStack(uint32_t stackSize, struct stack_t *processStack, uintptr_t handlerAddress){

    if((currentFrame - stackSize) < beginOfStack){
        return STACK_UNAVAILABLE;
    } else {
        //create stack
        processStack->end = currentFrame;
        processStack->currentAddress = currentFrame;
        currentFrame-=stackSize;
        processStack->begin = currentFrame;
        currentFrame-=4; // dont touch

        //insert handler

        //memoryCopy ((uintptr_t )&processHandler-1,processStack->end-8,8);
        processStack->currentAddress-=8;
        processStack->function=processStack->currentAddress+1;
        memoryCopy (handlerAddress,processStack->currentAddress,8);
        processStack->currentAddress-=4;
        return MEMORY_SUCCESS;
    }

}