CMAKE_MINIMUM_REQUIRED(VERSION 3.22.1)

SET(CMAKE_TOOLCHAIN_FILE /home/sondahi/Projects/gEmbedded-OS/toolchain.cmake)

PROJECT(gEmbedded-OS LANGUAGES ASM C)

ADD_EXECUTABLE(${PROJECT_NAME})

SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}.elf")

TARGET_COMPILE_OPTIONS(${PROJECT_NAME} PRIVATE -Wall -mcpu=cortex-m4 -mthumb -std=gnu11 -O3 -ggdb)

TARGET_LINK_OPTIONS(${PROJECT_NAME} PRIVATE -Wl,-fuse-ld=mold -nostdlib -T /home/sondahi/Projects/gEmbedded-OS/kernel/config/STM32F411.ld -Wl,-Map=${PROJECT_NAME}.map)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND arm-none-eabi-size ${PROJECT_NAME}.elf
        COMMAND arm-none-eabi-objcopy -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
        COMMAND arm-none-eabi-objcopy -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
        COMMAND arm-none-eabi-objdump --disassemble ${PROJECT_NAME}.elf > ${PROJECT_NAME}.dump)

ADD_SUBDIRECTORY(kernel)
ADD_SUBDIRECTORY(user)