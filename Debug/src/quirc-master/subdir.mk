################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/quirc-master/decode.c \
../src/quirc-master/identify.c \
../src/quirc-master/quirc.c \
../src/quirc-master/version_db.c 

OBJS += \
./src/quirc-master/decode.o \
./src/quirc-master/identify.o \
./src/quirc-master/quirc.o \
./src/quirc-master/version_db.o 

C_DEPS += \
./src/quirc-master/decode.d \
./src/quirc-master/identify.d \
./src/quirc-master/quirc.d \
./src/quirc-master/version_db.d 


# Each subdirectory must supply rules for building sources it contributes
src/quirc-master/%.o: ../src/quirc-master/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include/mysql -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


