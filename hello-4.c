#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#define DRIVER_AUTHOR "Benji Altman <benji@altmansoftwaredesign.com>"
#define DRIVER_DESC "Hello world version 4"


static int __init init_hello_4(void)
{
    printk(KERN_INFO "Hello world 4\n");
    return 0;
}

static void __exit cleanup_hello_4(void)
{
    printk(KERN_INFO "Goodbye world 4\n");
}

module_init(init_hello_4);
module_exit(cleanup_hello_4);

// No real preference between inline constant and defines at top.
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);

// This module uses /dev/testdevice. The MODULE_SUPPORTED DEVICE macro might be used in the future to help automatic configuration of modules, but is currently unused other than for documentation purposes.
MODULE_SUPPORTED_DEVICE("testdevice");