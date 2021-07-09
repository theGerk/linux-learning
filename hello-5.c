#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>

#define printinf(x) printk( KERN_INFO x )


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Benji Altman");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char* mystring = "blah";
static int myintArray[2] = { -1, -1, };
static int arr_argc = 0;

/**
 * module_param(foo, int, 0000)
 * The first param is the paramters name
 * The second param is it's data type
 * The final param is the permission bits,
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A lng integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");


/**
 * module_param_array(name, type, num, perm);
 * The first param is the paramter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third param is the pointer to the variable that will store the number of elements of the array initialized by the user at module loading time
 * The fourth param is the permission bits
 */
module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");


static int __init hello_5_init(void)
{
    int i;
    printinf("hello world\n");
    return 0;
}

static void __exit hello_5_exit(void)
{
    printinf("goodbye world\n");
}


module_init(hello_5_init);
module_exit(hello_5_exit);