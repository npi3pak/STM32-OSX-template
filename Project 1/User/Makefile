TARGET=demo.hex
EXECUTABLE=demo.elf

CC=arm-none-eabi-gcc
LD=arm-none-eabi-ld 
#LD=arm-none-eabi-gcc
AR=arm-none-eabi-ar
AS=arm-none-eabi-as
CP=arm-none-eabi-objcopy
OD=arm-none-eabi-objdump

BIN=$(CP) -O ihex 

DEFS = -DUSE_STDPERIPH_DRIVER -DSTM32F40_41xxx

MCU = cortex-m4
# MCFLAGS = -mcpu=$(MCU) -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork
MCFLAGS = -mcpu=$(MCU) -mthumb -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb-interwork -lgcc -lc -lm -lrdimon


# STM32_INCLUDES =-I../Utilities/STM32F4-Discovery \
# 	-I../CMSIS \
# 	-I../StdPerph \
# 	-I../StdPerph/inc \
# 	-I../StdPerph/src \
# 	-I../Startup \


STM32_INCLUDES =-I../CMSIS \
	-I../StdPerph \
	-I../StdPerph/inc \
	-I../StdPerph/src \
	-I../Startup \



OPTIMIZE       = -Os

CFLAGS	= $(MCFLAGS)  $(OPTIMIZE)  $(DEFS) -I./ -I./ $(STM32_INCLUDES)  -Wl,-T,../Startup/stm32_flash.ld
AFLAGS	= $(MCFLAGS) 
#-mapcs-float use float regs. small increase in code size


SRC = main.c \
	../Startup/stm32f4xx_it.c \
	../Startup/system_stm32f4xx.c \
	../StdPerph/src/stm32f4xx_syscfg.c \
	../StdPerph/src/misc.c \
	../StdPerph/src/stm32f4xx_gpio.c \
	../StdPerph/src/stm32f4xx_rcc.c \
	../StdPerph/src/stm32f4xx_exti.c



STARTUP = ../Startup/startup_stm32f4xx.s

OBJDIR = .
OBJ = $(SRC:%.c=$(OBJDIR)/%.o) 
OBJ += Startup.o

all: $(TARGET)

$(TARGET): $(EXECUTABLE)
	$(CP) -O ihex $^ $@

$(EXECUTABLE): $(SRC) $(STARTUP)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f Startup.lst  $(TARGET)  $(TARGET).lst $(OBJ) $(AUTOGEN)  $(TARGET).out  $(TARGET).hex  $(TARGET).map \
	 $(TARGET).dmp  $(TARGET).elf

	