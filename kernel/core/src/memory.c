#include "memory.h"


MEMORY_STATUS allocateStack(uint32_t stackSize, struct stack_t *processStack, uintptr_t processFunction, uintptr_t handlerAddress, uint32_t const handlerSize){

    uint32_t static currentFrame = END_OF_PSP;

    if((currentFrame - stackSize) < BEGIN_OF_PSP){
        return STACK_UNAVAILABLE;
    } else {
        //create stack
        processStack->end = currentFrame;
        processStack->currentAddress = currentFrame;
        currentFrame-=stackSize;
        processStack->begin = currentFrame;
        currentFrame-=4; // dont touch

        //insert handler

        processStack->currentAddress-=handlerSize;
        processStack->handler=processStack->currentAddress+1; // +1
        memoryCopy (handlerAddress-1,processStack->currentAddress,handlerSize);
        processStack->currentAddress-=4;

        // replace function

        uintptr_t volatile *handlerPtr = (uintptr_t *) (processStack->handler-1);
        handlerPtr++;
        handlerPtr++;
        *handlerPtr = processFunction;
        return MEMORY_SUCCESS;
    }

}