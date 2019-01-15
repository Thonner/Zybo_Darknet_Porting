################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

CC_SRCS += \
../src/main.cc 

C_SRCS += \
../src/activation_layer.c \
../src/activations.c \
../src/avgpool_layer.c \
../src/batchnorm_layer.c \
../src/blas.c \
../src/box.c \
../src/col2im.c \
../src/connected_layer.c \
../src/convolutional_layer.c \
../src/cost_layer.c \
../src/crnn_layer.c \
../src/crop_layer.c \
../src/darknet.c \
../src/data.c \
../src/deconvolutional_layer.c \
../src/detection_layer.c \
../src/detector.c \
../src/dropout_layer.c \
../src/gemm.c \
../src/gru_layer.c \
../src/hardcrap.c \
../src/im2col.c \
../src/image.c \
../src/iseg_layer.c \
../src/l2norm_layer.c \
../src/layer.c \
../src/list.c \
../src/local_layer.c \
../src/logistic_layer.c \
../src/lstm_layer.c \
../src/matrix.c \
../src/maxpool_layer.c \
../src/network.c \
../src/normalization_layer.c \
../src/option_list.c \
../src/parser.c \
../src/region_layer.c \
../src/reorg_layer.c \
../src/rnn_layer.c \
../src/route_layer.c \
../src/shortcut_layer.c \
../src/softmax_layer.c \
../src/tree.c \
../src/upsample_layer.c \
../src/utils.c \
../src/yolo_layer.c 

CC_DEPS += \
./src/main.d 

OBJS += \
./src/activation_layer.o \
./src/activations.o \
./src/avgpool_layer.o \
./src/batchnorm_layer.o \
./src/blas.o \
./src/box.o \
./src/col2im.o \
./src/connected_layer.o \
./src/convolutional_layer.o \
./src/cost_layer.o \
./src/crnn_layer.o \
./src/crop_layer.o \
./src/darknet.o \
./src/data.o \
./src/deconvolutional_layer.o \
./src/detection_layer.o \
./src/detector.o \
./src/dropout_layer.o \
./src/gemm.o \
./src/gru_layer.o \
./src/hardcrap.o \
./src/im2col.o \
./src/image.o \
./src/iseg_layer.o \
./src/l2norm_layer.o \
./src/layer.o \
./src/list.o \
./src/local_layer.o \
./src/logistic_layer.o \
./src/lstm_layer.o \
./src/main.o \
./src/matrix.o \
./src/maxpool_layer.o \
./src/network.o \
./src/normalization_layer.o \
./src/option_list.o \
./src/parser.o \
./src/region_layer.o \
./src/reorg_layer.o \
./src/rnn_layer.o \
./src/route_layer.o \
./src/shortcut_layer.o \
./src/softmax_layer.o \
./src/tree.o \
./src/upsample_layer.o \
./src/utils.o \
./src/yolo_layer.o 

C_DEPS += \
./src/activation_layer.d \
./src/activations.d \
./src/avgpool_layer.d \
./src/batchnorm_layer.d \
./src/blas.d \
./src/box.d \
./src/col2im.d \
./src/connected_layer.d \
./src/convolutional_layer.d \
./src/cost_layer.d \
./src/crnn_layer.d \
./src/crop_layer.d \
./src/darknet.d \
./src/data.d \
./src/deconvolutional_layer.d \
./src/detection_layer.d \
./src/detector.d \
./src/dropout_layer.d \
./src/gemm.d \
./src/gru_layer.d \
./src/hardcrap.d \
./src/im2col.d \
./src/image.d \
./src/iseg_layer.d \
./src/l2norm_layer.d \
./src/layer.d \
./src/list.d \
./src/local_layer.d \
./src/logistic_layer.d \
./src/lstm_layer.d \
./src/matrix.d \
./src/maxpool_layer.d \
./src/network.d \
./src/normalization_layer.d \
./src/option_list.d \
./src/parser.d \
./src/region_layer.d \
./src/reorg_layer.d \
./src/rnn_layer.d \
./src/route_layer.d \
./src/shortcut_layer.d \
./src/softmax_layer.d \
./src/tree.d \
./src/upsample_layer.d \
./src/utils.d \
./src/yolo_layer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O2 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../pcam_vdma_hdmi_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O2 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../pcam_vdma_hdmi_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


