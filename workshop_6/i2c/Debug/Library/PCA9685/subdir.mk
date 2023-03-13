################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Library/PCA9685/PCA9685.c 

OBJS += \
./Library/PCA9685/PCA9685.o 

C_DEPS += \
./Library/PCA9685/PCA9685.d 


# Each subdirectory must supply rules for building sources it contributes
Library/PCA9685/%.o Library/PCA9685/%.su: ../Library/PCA9685/%.c Library/PCA9685/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/user/Desktop/GL_tasks/workshop_6/i2c/Library/PCA9685" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Library-2f-PCA9685

clean-Library-2f-PCA9685:
	-$(RM) ./Library/PCA9685/PCA9685.d ./Library/PCA9685/PCA9685.o ./Library/PCA9685/PCA9685.su

.PHONY: clean-Library-2f-PCA9685

