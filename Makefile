#Generated by VisualKernel [http://visualkernel.com/].
#Use VisualKernel Project Properties to edit.

KERNEL_MODULE_NAME := kgdboe
KERNEL_MODULE_OBJECT_FILE_LIST := irqsync.o kgdboe_main.o kgdboe_io.o nethook.o netpoll_wrapper.o poll_copy.o spinhook.o timerhook.o

obj-m := $(KERNEL_MODULE_NAME).o
$(KERNEL_MODULE_NAME)-y += $(KERNEL_MODULE_OBJECT_FILE_LIST)
#ccflags-y := -ggdb -O0 -std=gnu99

ccflags-y += -include backport.h
#$(KERNEL_MODULE_NAME)-y += symbols.o
$(KERNEL_MODULE_NAME)-y += backport.o
