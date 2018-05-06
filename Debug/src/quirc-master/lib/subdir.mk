################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/quirc-master/lib/decode.c \
../src/quirc-master/lib/identify.c \
../src/quirc-master/lib/quirc.c \
../src/quirc-master/lib/version_db.c 

OBJS += \
./src/quirc-master/lib/decode.o \
./src/quirc-master/lib/identify.o \
./src/quirc-master/lib/quirc.o \
./src/quirc-master/lib/version_db.o 

C_DEPS += \
./src/quirc-master/lib/decode.d \
./src/quirc-master/lib/identify.d \
./src/quirc-master/lib/quirc.d \
./src/quirc-master/lib/version_db.d 


# Each subdirectory must supply rules for building sources it contributes
src/quirc-master/lib/%.o: ../src/quirc-master/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include/mysql -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


