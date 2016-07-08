/*
 * * hello−1.c − The simplest kernel module.
 * */
#include <linux/module.h>
/* Needed by all modules */
#include <linux/kernel.h>
/* Needed for KERN_INFO */
#include <linux/init.h> /* for module_init() and module_exit() macros*/
#include <linux/moduleparam.h> /* for modular params */
/**/

int x;
module_param(x, int, 0); //name,type, permission in sysfs for corresponding file
/* there is also support for arrays and strings */

int hello_init(void)
{
	printk(KERN_INFO "Hello world 1., x = %d\n", x); 
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
MODULE_PARM_DESC(z, "An integer"); /* "z" need not be declared already, in case if it is declared already then the modinfo
					command also shows the type(data type) of the variable, otherwise not */
MODULE_PARM_DESC(x, "An integer"); 
MODULE_LICENSE("GPL");
