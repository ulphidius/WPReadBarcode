################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/quirc-master/demo/camera.c \
../src/quirc-master/demo/convert.c \
../src/quirc-master/demo/demo.c \
../src/quirc-master/demo/demoutil.c \
../src/quirc-master/demo/dthash.c \
../src/quirc-master/demo/mjpeg.c \
../src/quirc-master/demo/scanner.c 

OBJS += \
./src/quirc-master/demo/camera.o \
./src/quirc-master/demo/convert.o \
./src/quirc-master/demo/demo.o \
./src/quirc-master/demo/demoutil.o \
./src/quirc-master/demo/dthash.o \
./src/quirc-master/demo/mjpeg.o \
./src/quirc-master/demo/scanner.o 

C_DEPS += \
./src/quirc-master/demo/camera.d \
./src/quirc-master/demo/convert.d \
./src/quirc-master/demo/demo.d \
./src/quirc-master/demo/demoutil.d \
./src/quirc-master/demo/dthash.d \
./src/quirc-master/demo/mjpeg.d \
./src/quirc-master/demo/scanner.d 


# Each subdirectory must supply rules for building sources it contributes
src/quirc-master/demo/%.o: ../src/quirc-master/demo/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/include/mysql -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


