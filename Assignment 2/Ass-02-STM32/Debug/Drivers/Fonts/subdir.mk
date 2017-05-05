################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Fonts/font12.c \
../Drivers/Fonts/font16.c \
../Drivers/Fonts/font20.c \
../Drivers/Fonts/font24.c \
../Drivers/Fonts/font8.c 

OBJS += \
./Drivers/Fonts/font12.o \
./Drivers/Fonts/font16.o \
./Drivers/Fonts/font20.o \
./Drivers/Fonts/font24.o \
./Drivers/Fonts/font8.o 

C_DEPS += \
./Drivers/Fonts/font12.d \
./Drivers/Fonts/font16.d \
./Drivers/Fonts/font20.d \
./Drivers/Fonts/font24.d \
./Drivers/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Fonts/%.o: ../Drivers/Fonts/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -D__weak=__attribute__((weak)) -D__packed=__attribute__((__packed__)) -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/Zandor Teseling/Documents/Sem1 2017/ELEC3730_Embedded/Ass-02-STM32/Inc" -I"C:/Users/Zandor Teseling/Documents/Sem1 2017/ELEC3730_Embedded/Ass-02-STM32/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/Zandor Teseling/Documents/Sem1 2017/ELEC3730_Embedded/Ass-02-STM32/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Zandor Teseling/Documents/Sem1 2017/ELEC3730_Embedded/Ass-02-STM32/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/Zandor Teseling/Documents/Sem1 2017/ELEC3730_Embedded/Ass-02-STM32/Drivers/CMSIS/Include" -I"C:/Users/Zandor Teseling/Documents/Sem1 2017/ELEC3730_Embedded/Ass-02-STM32/Drivers/BSP" -I"C:/Users/Zandor Teseling/Documents/Sem1 2017/ELEC3730_Embedded/Ass-02-STM32/Drivers/Fonts" -I"C:/Users/Zandor Teseling/Documents/Sem1 2017/ELEC3730_Embedded/Ass-02-STM32/Inc"  -Os -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


