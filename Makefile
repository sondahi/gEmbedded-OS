INCLUDE_DIRECTORIES=-Ikernel/core/include -Ikernel/driver/include -Ikernel/userinterface/include -Iuser/include
C_SOURCE_DIRECTORIES=kernel/core/src/*.c kernel/driver/src/*.c kernel/userinterface/src/*.c user/src/*.c
ASM_SOURCE_DIRECTORIES=kernel/core/src/*.S

BUILD_DIRECTORY=build
FINAL_NAME=gEmbedded

GCC_COMPILER=arm-none-eabi-gcc
MACHINE=-mcpu=cortex-m4
INSTRUCTION_SET=-mthumb
C_STANDARD=-std=gnu11
OPTIMIZATION=-O3
GCC_DEBUG=-ggdb
GCC_COMPILE_FLAGS=-c -Wall $(MACHINE) $(INSTRUCTION_SET) $(C_STANDARD) $(OPTIMIZATION) ${GCC_DEBUG} $(INCLUDE_DIRECTORIES) $(C_SOURCE_DIRECTORIES) $(ASM_SOURCE_DIRECTORIES)

#ASM_COMPILER=arm-none-eabi-as
#ASM_DEBUG=-D
#ASM_COMPILE_FLAGS=-c --warn $(MACHINE) $(INCLUDE_DIRECTORIES) ${ASM_DEBUG} $(ASM_SOURCE_DIRECTORIES) -o asm.o

LINKER=arm-none-eabi-ld
LINKER_TYPE=-fuse-ld=mold
LINKER_FILE=-T kernel/config/STM32F411.ld
LIBRARY=-nostdlib
OBJECTS=*.o
MAP_NAME=-Map=$(BUILD_DIRECTORY)/$(FINAL_NAME).map
EXECUTABLE_NAME=-o $(BUILD_DIRECTORY)/$(FINAL_NAME).elf
LINK_FLAGS=$(LINKER_TYPE) $(LINKER_FILE) $(LIBRARY) ${OBJECTS} $(MAP_NAME) $(EXECUTABLE_NAME)

SIZER=arm-none-eabi-size
SIZE_FLAGS=--format=berkeley "$(BUILD_DIRECTORY)/$(FINAL_NAME).elf" > "$(BUILD_DIRECTORY)/$(FINAL_NAME).size"

DUMPER=arm-none-eabi-objdump
DUMP_FLAGS=--disassemble "$(BUILD_DIRECTORY)/$(FINAL_NAME).elf" > "$(BUILD_DIRECTORY)/$(FINAL_NAME).dump"

all : outputs

outputs : build_directory
	$(GCC_COMPILER) $(GCC_COMPILE_FLAGS)
	#$(ASM_COMPILER) $(ASM_COMPILE_FLAGS)
	$(LINKER) $(LINK_FLAGS)
	$(SIZER) $(SIZE_FLAGS)
	$(DUMPER) $(DUMP_FLAGS)

build_directory : clean
	if ! [ -d "$(BUILD_DIRECTORY)" ]; then mkdir $(BUILD_DIRECTORY); fi

clean :
	if [ -d "$(BUILD_DIRECTORY)" ]; then rm -r $(BUILD_DIRECTORY); fi
	rm -rf *.o
