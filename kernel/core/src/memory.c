#include "memory.h"

extern uint32_t _ePSP;
extern uint32_t _bPSP;

uint32_t static const endOfUserStack = (uint32_t)&_ePSP;
uint32_t static userStackPointer = endOfUserStack;
uint32_t static const beginOfUserStack = (uint32_t)&_bPSP;

__attribute__((naked)) void memoryCopy(uintptr_t *sourceAddress, uintptr_t *destinationAddress, uint32_t blockSize){

    __asm__ volatile ("cbz r2, memoryCopyExit");
    __asm__ volatile ("sub r2, r2, #0x01");
    __asm__ volatile ("ldrb r3, [r0,r2]");
    __asm__ volatile ("strb r3, [r1,r2]");
    __asm__ volatile ("b memoryCopy");
    __asm__ volatile ("memoryCopyExit:");
    __asm__ volatile ("bx lr");

}

__attribute__((naked)) void memoryFill(uintptr_t *sourceAddress, uint32_t blockSize, uint32_t value){

    __asm__ volatile ("cbz r1, memoryFillExit");
    __asm__ volatile ("sub r1, r1, #0x01");
    __asm__ volatile ("strb r2, [r0,r1]");
    __asm__ volatile ("b memoryFill");
    __asm__ volatile ("memoryFillExit:");
    __asm__ volatile ("bx lr");

}

void allocateStack(uint32_t stackSize, struct stack_t *processStack){
    // total stack kontrol if begine throw exception

    processStack->stackBegin = userStackPointer;
    processStack->currentPointer = userStackPointer;
    userStackPointer-=stackSize;
    processStack->stackEnd = userStackPointer;

}