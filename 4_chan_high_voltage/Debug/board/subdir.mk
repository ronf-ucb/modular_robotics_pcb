################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../board/board.c \
../board/clock_config.c \
../board/pin_mux.c 

OBJS += \
./board/board.o \
./board/clock_config.o \
./board/pin_mux.o 

C_DEPS += \
./board/board.d \
./board/clock_config.d \
./board/pin_mux.d 


# Each subdirectory must supply rules for building sources it contributes
board/%.o: ../board/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DFRDM_K64F -DFREEDOM -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\board" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\source" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\drivers" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\CMSIS" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\utilities" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\startup" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


