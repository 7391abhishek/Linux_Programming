/*
 * * hello−1.c − The simplest kernel module.
 * */
#include <linux/module.h>
/* Needed by all modules */
#include <linux/kernel.h>
/* Needed for KERN_INFO */
#include <linux/init.h> /* for module_init() and module_exit() macros*/

void hello_exit(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}

module_exit(hello_exit);
MODULE_LICENSE("GPL");
