#-------------------------------------------------------------------------------
# ARM-GCC Makefile
# COMP3215 Real-Time Computing and Embedded Systems
# Rhys Thomas
#-------------------------------------------------------------------------------

CC        = arm-none-eabi-gcc
MAKEFLAGS = -j4

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

all: RTOS_Blink.axf

-include Makefile.deps

Makefile.deps: $(SRC)
	$(CC) $(CFLAGS) $(INC) -MM $^ > Makefile.deps

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -o $@ $<

RTOS_Blink.axf: $(OBJ)
	@echo 'Building target: $@'
	$(CC) $(LDFLAGS) -o $@ $(OBJ)
	@echo 'Finished building target: $@'

#TODO - Not yet working
flash: RTOS_Blink.axf
	arm-none-eabi-gdb -x flash.txt

clean:
	-rm $(OBJ)
	-rm Makefile.deps
	-rm RTOS_Blink.axf
