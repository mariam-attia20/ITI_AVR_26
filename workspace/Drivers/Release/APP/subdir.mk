################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/DC_motor.c \
../APP/Interrupt.c \
../APP/KPD_ASS.c \
../APP/LCD_CHAR.c \
../APP/TIMERS.c \
../APP/as_dc_EXTI.c \
../APP/deep_switch.c \
../APP/keypad.c \
../APP/labs.c \
../APP/main.c \
../APP/push_bottom.c \
../APP/sev_seg.c \
../APP/stepper_motor.c \
../APP/temp_read.c 

OBJS += \
./APP/DC_motor.o \
./APP/Interrupt.o \
./APP/KPD_ASS.o \
./APP/LCD_CHAR.o \
./APP/TIMERS.o \
./APP/as_dc_EXTI.o \
./APP/deep_switch.o \
./APP/keypad.o \
./APP/labs.o \
./APP/main.o \
./APP/push_bottom.o \
./APP/sev_seg.o \
./APP/stepper_motor.o \
./APP/temp_read.o 

C_DEPS += \
./APP/DC_motor.d \
./APP/Interrupt.d \
./APP/KPD_ASS.d \
./APP/LCD_CHAR.d \
./APP/TIMERS.d \
./APP/as_dc_EXTI.d \
./APP/deep_switch.d \
./APP/keypad.d \
./APP/labs.d \
./APP/main.d \
./APP/push_bottom.d \
./APP/sev_seg.d \
./APP/stepper_motor.d \
./APP/temp_read.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


