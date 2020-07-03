#ifndef INCLUDED_EDDYDRV_H
#define INCLUDED_EDDYDRV_H

/* 模块公共的资源 */
#include "eddymodule.h"

/* 来源eddydrv-imp模块*/
extern char* get_caller(void);
extern int do_register_stuff(void);
extern void do_deregister_stuff(void);

#endif /* INCLUDED_EDDYDRV_H */
