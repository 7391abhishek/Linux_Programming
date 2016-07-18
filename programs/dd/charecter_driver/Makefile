obj-m += char.o # final module to be created

KERNELDIR  := /lib/modules/$(shell uname -r)/build
PWD    	   := $(shell pwd)
OUTPUT_FILES := *.o *.ko *.mod.* *.symvers *.order

all:
	    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	    rm -rf $(OUTPUT_FILES)
