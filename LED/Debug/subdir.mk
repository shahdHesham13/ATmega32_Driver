################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../LED_config.c \
../LED_prog.c \
../Switch_config.c \
../Switch_prog.c \
../main.c 

OBJS += \
./DIO_prog.o \
./LED_config.o \
./LED_prog.o \
./Switch_config.o \
./Switch_prog.o \
./main.o 

C_DEPS += \
./DIO_prog.d \
./LED_config.d \
./LED_prog.d \
./Switch_config.d \
./Switch_prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


