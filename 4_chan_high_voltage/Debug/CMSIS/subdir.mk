################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/system_MK64F12.c 

OBJS += \
./CMSIS/system_MK64F12.o 

C_DEPS += \
./CMSIS/system_MK64F12.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/%.o: ../CMSIS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DFRDM_K64F -DFREEDOM -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\board" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\source" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\drivers" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\CMSIS" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\utilities" -I"C:\Users\ljiang\Documents\MCUXpressoIDE_10.1.0_589\workspace\4_chan_high_voltage\startup" -O0 -fno-common -g -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


