/*
 *  create by kevin
 *       2020.07.02
 */

#include "include/eddydrv.h"

static int __init eddydrv_init(void) {
	eddydrv_info("eddydrv module init .. %s",get_caller());
	if ( do_register_stuff() )
		eddydrv_err("register module fail");
    	return 0;
}
 
static void __exit eddydrv_exit(void) {
	do_deregister_stuff();
	eddydrv_info("eddydrv module exit ..");
}

module_init(eddydrv_init);
module_exit(eddydrv_exit);
