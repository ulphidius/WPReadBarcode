################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/config.c \
../src/createXml.c \
../src/main.c \
../src/menu.c 

OBJS += \
./src/config.o \
./src/createXml.o \
./src/main.o \
./src/menu.o 

C_DEPS += \
./src/config.d \
./src/createXml.d \
./src/main.d \
./src/menu.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include/mysql -I/usr/include/libxml2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


