#ifndef TIME_H
#define TIME_H

    #include "common.h"

    /*
     * The processor has a 24-bit system timer, SysTick, that counts down from the reload value to zero reloads (wraps to)
     * the value in the STK_LOAD register on the next clock edge, then counts down on subsequent clocks.
     * When the processor is halted for debugging the counter does not decrement.
     * The SysTick counter runs on the processor clock. If this clock signal is stopped for low power mode, the SysTick
     * counter stops.
     */

    struct STK_CTRL_t{
        uintptr_t enable_rw         : 1;
        uintptr_t tickInt_rw        : 1;
        uintptr_t clockSource_rw    : 1;
        uintptr_t                   : 13;
        uintptr_t countFlag_rw      : 1;
        uintptr_t                   : 15;
    };

    struct STK_LOAD_t{
        uintptr_t reloadValue_rw    : 24;
        uintptr_t                   : 8;
    };

    struct STK_VAL_t{
        uintptr_t currentValue_rw   : 24;
        uintptr_t                   : 8;
    };

    struct STK_CALIB_t{
        uintptr_t tenMS_r           : 24;
        uintptr_t                   : 6;
        uintptr_t skew_r            : 1;
        uintptr_t noReference_r     : 1;
    };

    struct ST_t{
        struct STK_CTRL_t STK_CTRL;     // Privileged
        struct STK_LOAD_t STK_LOAD;     // Privileged
        struct STK_VAL_t STK_VAL;       // Privileged
        struct STK_CALIB_t STK_CALIB;   // Privileged
    };

    #define AHB_CLOCK_SPEED                 (100000000U)
    #define SEC                             AHB_CLOCK_SPEED
    #define MIL_SEC                         (SEC / 1000U)
    #define MIC_SEC                         (MIL_SEC / 1000U)

    #define DEFAULT_PROCESS_SWITCH          ((100) * (MIL_SEC) - (1U))
    #define CLOCK_SOURCE_AHB                (0X1U)
    #define CLOCK_SOURCE_AHB8               (0X0)


    #define ST ((volatile struct ST_t *)    (0xE000E010))

    void initSystemTimer(void );

#endif //TIME_H
