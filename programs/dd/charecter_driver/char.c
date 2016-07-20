/*
 * * hello−1.c − The simplest kernel module.
 * */
#include <linux/module.h>
/* Needed by all modules */
#include <linux/kernel.h>
/* Needed for KERN_INFO */
#include <linux/init.h> /* for module_init() and module_exit() macros*/
#include <linux/moduleparam.h> /* for modular params */
#include <linux/fs.h>
/**/
static int dev_release (struct inode *inodep, struct file *filp );
static int dev_open(struct inode *inodep, struct file *filp);
static ssize_t dev_read(struct file *filp, char __user *userp, size_t sizep, loff_t *offp);
static ssize_t dev_write (struct file *filp, const char __user *userp, size_t sizep, loff_t *offp);
#ifdef GNU_STYLE
/* Use gcc extensions, thus not more portable */
static struct file_operations fops = {
	read	: 	device_read,
	write	: 	device_write,
	open	:	device_open,
	release	: 	device_release
};
#else 
/* More portable */
static struct file_operations fops = {
	.read	= 	dev_read,
	.write	= 	dev_write,
	.open	=	dev_open,
	.release= 	dev_release
};
#endif

int x;
module_param(x, int, 0); //name,type, permission in sysfs for corresponding file
/* there is also support for arrays and strings */

unsigned int dev_major = 0;
const char *dev_name = "mcd"; /* My char device */

static int dev_release (struct inode *inodep, struct file *filp )
{
	printk(KERN_INFO "%s\n", __func__);
	module_put(THIS_MODULE);
	return 0;
}

static int dev_open(struct inode *inodep, struct file *filp)
{
	printk(KERN_INFO "%s\n", __func__);
	/* Whenever a file is opened, a counter should be incremented to 
	 * keep track of the number of applications that are using the file */
	try_module_get(THIS_MODULE);
	return 0;
}

static ssize_t dev_read(struct file *filp, char __user *userp, 
		size_t sizep, loff_t *offp)
{
	printk(KERN_INFO "%s\n", __func__);
	return 0;
}

static ssize_t dev_write (struct file *filp, const char __user *userp, 
		size_t sizep, loff_t *offp)
{
	printk(KERN_INFO "%s\n", __func__);
	return 0;
}

int hello_init(void)
{
	uint32_t major;
	printk(KERN_INFO "Hello world 1., x = %d\n", x); 
	printk(KERN_INFO "Major number = %d, name = %s\n", 
		dev_major, dev_name);
	major = register_chrdev(0, dev_name, &fops);
	if(major < 0) {
		printk(KERN_INFO "Failed to register device %s\n", dev_name);
		return 1;
	}else 
		printk(KERN_INFO "Module registered successfully with majot number = %d\n", major);
	
	
	/*
	 * * A non 0 return means init_module failed; module can't be loaded.
	 * */
	return 0;
}
void hello_exit(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}


module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Abhishek Kumar Choubey");
