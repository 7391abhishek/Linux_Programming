obj-m += hello.o
obj-m += hello_2.o
KERNELDIR  := /lib/modules/$(shell uname -r)/build
PWD    	   := $(shell pwd)
OUTPUT_FILES := *.o *.ko *.mod.* *.symvers *.order

all:
	    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	    rm -rf $(OUTPUT_FILES)
