#include "memory.h"
#include "exception.h"

MEMORY_STATUS allocateStack(struct stack_t *stack){

    uint32_t static currentFrame = END_OF_PSP;

    if((currentFrame - stack->size) < BEGIN_OF_PSP){
        return STACK_UNAVAILABLE;
    } else {
        //create stack
        stack->end = currentFrame;
        stack->current = (uintptr_t *)stack->end;
        currentFrame-=stack->size;
        stack->begin = currentFrame;
        currentFrame-=4; // dont touch

        //insert handler
        stack->current-=2;
        memoryCopy (stack->handlerAddress-1, (uint32_t) stack->current, stack->handlerSize);
        stack->handlerAddress = ((uint32_t) stack->current)+1; // change address to sram
        // replace function
        *(stack->current+2) = stack->functionAddress;

        // fill stack entry
        *--stack->current = DUMMY_XPSR;
        *--stack->current = stack->handlerAddress;
        *--stack->current = THREAD_NOFPU_PSP;
        for (int i = 12; i >=0 ; --i) {
            *--stack->current = i;
        }

        return MEMORY_SUCCESS;
    }

}