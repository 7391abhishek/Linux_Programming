obj-m += hello.o # final module to be created
obj-m += hello_2.o
obj-m += hello_3.o
obj-m += mod.o

mod-objs := mod1.o mod2.o  # dependencies for a module, are declared like this


KERNELDIR  := /lib/modules/$(shell uname -r)/build
PWD    	   := $(shell pwd)
OUTPUT_FILES := *.o *.ko *.mod.* *.symvers *.order

all:
	    $(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	    rm -rf $(OUTPUT_FILES)
