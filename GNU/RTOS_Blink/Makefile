#-------------------------------------------------------------------------------
# ARM-GCC Makefile
# COMP3215 Real-Time Computing and Embedded Systems
# Rhys Thomas
#-------------------------------------------------------------------------------

CC        = arm-none-eabi-gcc
MAKEFLAGS = -j4 --quiet

#-------------------------------------------------------------------------------
# PROJECT FILES
#-------------------------------------------------------------------------------

SRC  = $(wildcard ./CMSIS/*.c)
SRC += $(wildcard ./freertos/*.c)
SRC += $(wildcard ./source/*.c)
SRC += $(wildcard ./startup/*.c)

OBJ  = $(patsubst %.c,%.o,$(SRC))
INC  = -I./CMSIS -I./freertos -I./source -I./startup \
	-I/Applications/MCUXpressoIDE_10.0.2_411/ide/tools/features/include

#-------------------------------------------------------------------------------
# COMPILER FLAGS
#-------------------------------------------------------------------------------

CFLAGS  = -DDEBUG
CFLAGS += -DCPU_MKW41Z512VHT4
CFLAGS += --specs=nosys.specs
CFLAGS += -O0
CFLAGS += -fno-common
CFLAGS += -g3
CFLAGS += -Wall
CFLAGS += -c
CFLAGS += -fmessage-length=0
CFLAGS += -fno-builtin
CFLAGS += -ffunction-sections
CFLAGS += -fdata-sections
CFLAGS += -mcpu=cortex-m0plus
CFLAGS += -mthumb

#-------------------------------------------------------------------------------
# LINKER FLAGS
#-------------------------------------------------------------------------------

LDFLAGS  = -Xlinker
LDFLAGS += -Map="RTOS_Blink.map"
LDFLAGS += -Xlinker
LDFLAGS += --gc-sections
LDFLAGS += -Xlinker
LDFLAGS += -print-memory-usage
LDFLAGS += -mcpu=cortex-m0plus
LDFLAGS += -mthumb
LDFLAGS += -T RTOS_Blink_Debug.ld

#-------------------------------------------------------------------------------
# TARGET RULES
#-------------------------------------------------------------------------------

all: RTOS_Blink.elf

-include Makefile.deps

Makefile.deps: $(SRC)
	$(CC) $(CFLAGS) $(INC) -MM $^ > Makefile.deps

%.o: %.c
	@echo 'Compiling: $@'
	$(CC) $(CFLAGS) $(INC) -o $@ $<

RTOS_Blink.elf: $(OBJ)
	@echo ' '
	@echo 'Building target: $@'
	$(CC) $(LDFLAGS) -o $@ $(OBJ)
	@echo 'Finished building target: $@'

flash: RTOS_Blink.elf
	@echo 'Copying to binary...'
	arm-none-eabi-objcopy -O binary $< RTOS_Blink.bin
	@echo 'Programming...'
	cp RTOS_Blink.bin /Volumes/FRDM-KW41ZJ
	@echo 'Done.'

clean:
	@echo 'Cleaning...'
	-rm $(OBJ)
	-rm Makefile.deps
	-rm RTOS_Blink.elf
	-rm RTOS_Blink.bin
