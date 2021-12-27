################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/SENDER_RECIVER/SENDER_RECIVER_Program.c 

OBJS += \
./APP/SENDER_RECIVER/SENDER_RECIVER_Program.o 

C_DEPS += \
./APP/SENDER_RECIVER/SENDER_RECIVER_Program.d 


# Each subdirectory must supply rules for building sources it contributes
APP/SENDER_RECIVER/%.o: ../APP/SENDER_RECIVER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


