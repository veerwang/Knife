/*!
	\file    utils.c
	\brief   manage rcu module

	\version 2023-08-12, V1.0
	\author	 kevin.wang
	\note    none
*/

#include <stdbool.h>
#include <string.h>

struct rcu_unit_t {
	/// RCU module name
	char name[10];
	/// RCU module be used times
	int used_account;
};

/// types RCU need to be managered
enum rcu_type_e {
	GPIOA = 0,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	GPIOI,
	MAX_RCU_TYPES,
};

static struct rcu_unit_t system_rcu_resource[MAX_RCU_TYPES] = {
	[GPIOA] = {
		.name = "GPIOA",
		.used_account = 0,
	},

	[GPIOB] = {
		.name = "GPIOB",
		.used_account = 0,
	},

	[GPIOC] = {
		.name = "GPIOC",
		.used_account = 0,
	},

	[GPIOD] = {
		.name = "GPIOD",
		.used_account = 0,
	},

	[GPIOE] = {
		.name = "GPIOE",
		.used_account = 0,
	},

	[GPIOF] = {
		.name = "GPIOF",
		.used_account = 0,
	},

	[GPIOG] = {
		.name = "GPIOG",
		.used_account = 0,
	},

	[GPIOH] = {
		.name = "GPIOH",
		.used_account = 0,
	},

	[GPIOI] = {
		.name = "GPIOI",
		.used_account = 0,
	},
};

/*!
	\brief			register rcu module doing stuff
	\param[in]		none
	\param[out]		none
	\retval			none
*/
static void rcu_mrg_register_enable(void)
{
}
/*!
	\brief			register rcu module diable doing stuff
	\param[in]		none
	\param[out]		none
	\retval			none
*/
static void rcu_mrg_register_disable(void)
{
}

/*!
	\brief			initialize rcu manager account
	\param[in]		none
	\param[out]		none
	\retval			none
*/
void rcu_mrg_init(void)
{
	for (int i = 0; i < MAX_RCU_TYPES; i++) {
		system_rcu_resource[i].used_account = 0;
	}
}

/*!
	\brief			register rcu module
	\param[in]		name: RCU name
	\param[out]		none
	\retval			true: register success, false: fail
*/
bool rcu_mrg_register(char* name)
{
	bool status = false;
	for (int i = 0; i < MAX_RCU_TYPES; i++) {
		/// increase rcu used account
		if (0 == strcmp(system_rcu_resource[i].name, name)) {
			system_rcu_resource[i].used_account += 1;
			if (1 == system_rcu_resource[i].used_account) {
				rcu_mrg_register_enable();
			}
			status = true;
			break;
		}
	}
	return status;
}

/*!
	\brief			unregister rcu module
	\param[in]		name: RCU name
	\param[out]		none
	\retval			none
*/
bool rcu_mrg_unregister(char* name)
{
	bool status = false;
	for (int i = 0; i < MAX_RCU_TYPES; i++) {
		/// increase rcu used account
		if (0 == strcmp(system_rcu_resource[i].name, name)) {
			system_rcu_resource[i].used_account -= 1;
			if (system_rcu_resource[i].used_account == 0) {
				rcu_mrg_register_disable();
				status = true;
				break;
			}
		}
	}
	return status;
}

/*!
	\brief			check wheather all system resource is release
	\param[in]		none
	\param[out]		none
	\retval			true: all release, false: not yet
*/
bool rcu_mrg_check_release(void)
{
	bool status = false;
	for (int i = 0; i < MAX_RCU_TYPES; i++) {
		if (system_rcu_resource[i].used_account != 0) {
			return status;
		}
	}
	status = true;
	return status;
}
