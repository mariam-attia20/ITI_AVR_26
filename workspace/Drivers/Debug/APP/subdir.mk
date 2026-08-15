################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/DC_motor.c \
../APP/FreeARTOS_lab.c \
../APP/Interrupt.c \
../APP/KPD_ASS.c \
../APP/LCD_CHAR.c \
../APP/LCD_ICU.c \
../APP/SPI.c \
../APP/TIMERS.c \
../APP/UART_LAD.c \
../APP/as_dc_EXTI.c \
../APP/buzzer_timer1_adc.c \
../APP/deep_switch.c \
../APP/keypad.c \
../APP/labs.c \
../APP/led_pwm.c \
../APP/main.c \
../APP/push_bottom.c \
../APP/servo_pwm.c \
../APP/sev_seg.c \
../APP/stepper_motor.c \
../APP/temp_read.c \
../APP/timer_lab.c \
../APP/wdt.c 

OBJS += \
./APP/DC_motor.o \
./APP/FreeARTOS_lab.o \
./APP/Interrupt.o \
./APP/KPD_ASS.o \
./APP/LCD_CHAR.o \
./APP/LCD_ICU.o \
./APP/SPI.o \
./APP/TIMERS.o \
./APP/UART_LAD.o \
./APP/as_dc_EXTI.o \
./APP/buzzer_timer1_adc.o \
./APP/deep_switch.o \
./APP/keypad.o \
./APP/labs.o \
./APP/led_pwm.o \
./APP/main.o \
./APP/push_bottom.o \
./APP/servo_pwm.o \
./APP/sev_seg.o \
./APP/stepper_motor.o \
./APP/temp_read.o \
./APP/timer_lab.o \
./APP/wdt.o 

C_DEPS += \
./APP/DC_motor.d \
./APP/FreeARTOS_lab.d \
./APP/Interrupt.d \
./APP/KPD_ASS.d \
./APP/LCD_CHAR.d \
./APP/LCD_ICU.d \
./APP/SPI.d \
./APP/TIMERS.d \
./APP/UART_LAD.d \
./APP/as_dc_EXTI.d \
./APP/buzzer_timer1_adc.d \
./APP/deep_switch.d \
./APP/keypad.d \
./APP/labs.d \
./APP/led_pwm.d \
./APP/main.d \
./APP/push_bottom.d \
./APP/servo_pwm.d \
./APP/sev_seg.d \
./APP/stepper_motor.d \
./APP/temp_read.d \
./APP/timer_lab.d \
./APP/wdt.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


