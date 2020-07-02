/*
 *  create by kevin
 *       2020.07.02
 */

#include "include/eddydrv.h"

static int eddy_probe(struct platform_device *pdev) {
	int result;
	eddydrv_info("eddydrv driver probe");
	result = do_register_stuff();
	if ( result )
		eddydrv_info("eddydrv driver register fail");
	return result;
}

static int eddydrv_remove(struct platform_device *pdev) {
	do_deregister_stuff();
	eddydrv_info("eddydrv driver remove");
	return 0;
}

static struct of_device_id eddy_of_match[] = {
	{ .compatible = "vendor,eddy", },
	{ /* end of list */ },
};
MODULE_DEVICE_TABLE(of, eddy_of_match);

static struct platform_driver eddy_driver = {
	.driver = {
		.name   = DRIVER_NAME,    // 与platform_device中的要一样
		.owner  = THIS_MODULE,
		.of_match_table	= eddy_of_match,
	},
	.probe		= eddy_probe,
	.remove		= eddydrv_remove,
};


static int __init eddydrv_init(void) {
	eddydrv_info("eddydrv module init .. %s",get_caller());
	return platform_driver_register(&eddy_driver);
}
 
static void __exit eddydrv_exit(void) {
	platform_driver_unregister(&eddy_driver);
	eddydrv_info("eddydrv module exit ..");
}

module_init(eddydrv_init);
module_exit(eddydrv_exit);
