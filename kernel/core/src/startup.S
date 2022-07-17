    .syntax unified
    .cpu cortex-m4
    .thumb

    #include "memory.h"
    #include "mode.h"
    #include "vectors.h"

    .global Reset_Handler

    .section .text
    .type Reset_Handler, %function
Reset_Handler:
    ldr r0, =_eMSP
    bl setMSP

    ldr r0, =_ePSP
    bl setPSP

    mov r0, #SYSTEM_MODE
    bl setMode

    ldr r0, =_eROM
    ldr r1, =_bROMtoSRAM
    ldr r2, =_eROMtoSRAM
    sub r2, r2, r1
    bl memoryCopy

    ldr r0, =_bSRAM
    ldr r1, =_eSRAM
    sub r1, r1, r0
    mov r2, #BSS_DEFAULT_VALUE
    bl memoryFill

    bl systemInit;

    mov r0, #APPLICATION_MODE
    bl setMode

    bl test

    bl Default_Handler

    .section .isr_vector,"a",%progbits
    .type Vector_Table, %object
Vector_Table:
    .word  0x00000000
    .word  Reset_Handler
    .word  NMI_Handler
    .word  HardFault_Handler
    .word  MemManage_Handler
    .word  BusFault_Handler
    .word  UsageFault_Handler
    .word  0
    .word  0
    .word  0
    .word  0
    .word  SVC_Handler
    .word  DebugMon_Handler
    .word  0
    .word  PendSV_Handler
    .word  SysTick_Handler
    .word  WWDG_IRQHandler
    .word  PVD_IRQHandler
    .word  TAMP_STAMP_IRQHandler
    .word  RTC_WKUP_IRQHandler
    .word  FLASH_IRQHandler
    .word  RCC_IRQHandler
    .word  EXTI0_IRQHandler
    .word  EXTI1_IRQHandler
    .word  EXTI2_IRQHandler
    .word  EXTI3_IRQHandler
    .word  EXTI4_IRQHandler
    .word  DMA1_Stream0_IRQHandler
    .word  DMA1_Stream1_IRQHandler
    .word  DMA1_Stream2_IRQHandler
    .word  DMA1_Stream3_IRQHandler
    .word  DMA1_Stream4_IRQHandler
    .word  DMA1_Stream5_IRQHandler
    .word  DMA1_Stream6_IRQHandler
    .word  ADC_IRQHandler
    .word  0
    .word  0
    .word  0
    .word  0
    .word  EXTI9_5_IRQHandler
    .word  TIM1_BRK_TIM9_IRQHandler
    .word  TIM1_UP_TIM10_IRQHandler
    .word  TIM1_TRG_COM_TIM11_IRQHandler
    .word  TIM1_CC_IRQHandler
    .word  TIM2_IRQHandler
    .word  TIM3_IRQHandler
    .word  TIM4_IRQHandler
    .word  I2C1_EV_IRQHandler
    .word  I2C1_ER_IRQHandler
    .word  I2C2_EV_IRQHandler
    .word  I2C2_ER_IRQHandler
    .word  SPI1_IRQHandler
    .word  SPI2_IRQHandler
    .word  USART1_IRQHandler
    .word  USART2_IRQHandler
    .word  0
    .word  EXTI15_10_IRQHandler
    .word  RTC_Alarm_IRQHandler
    .word  OTG_FS_WKUP_IRQHandler
    .word  0
    .word  0
    .word  0
    .word  0
    .word  DMA1_Stream7_IRQHandler
    .word  0
    .word  SDIO_IRQHandler
    .word  TIM5_IRQHandler
    .word  SPI3_IRQHandler
    .word  0
    .word  0
    .word  0
    .word  0
    .word  DMA2_Stream0_IRQHandler
    .word  DMA2_Stream1_IRQHandler
    .word  DMA2_Stream2_IRQHandler
    .word  DMA2_Stream3_IRQHandler
    .word  DMA2_Stream4_IRQHandler
    .word  0
    .word  0
    .word  0
    .word  0
    .word  0
    .word  0
    .word  OTG_FS_IRQHandler
    .word  DMA2_Stream5_IRQHandler
    .word  DMA2_Stream6_IRQHandler
    .word  DMA2_Stream7_IRQHandler
    .word  USART6_IRQHandler
    .word  I2C3_EV_IRQHandler
    .word  I2C3_ER_IRQHandler
    .word  0
    .word  0
    .word  0
    .word  0
    .word  0
    .word  0
    .word  0
    .word  FPU_IRQHandler
    .word  0
    .word  0
    .word  SPI4_IRQHandler
    .word  SPI5_IRQHandler

    .end
