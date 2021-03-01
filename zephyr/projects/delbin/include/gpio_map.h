/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef __ZEPHYR_GPIO_MAP_H
#define __ZEPHYR_GPIO_MAP_H

#include <devicetree.h>
#include <gpio_signal.h>

#define GPIO_AC_PRESENT		NAMED_GPIO(acok_od)
#define GPIO_CPU_PROCHOT	NAMED_GPIO(ec_prochot_odl)
#define GPIO_EC_PCH_SYS_PWROK	NAMED_GPIO(ec_pch_sys_pwrok)
#define GPIO_EC_PCH_WAKE_ODL	NAMED_GPIO(ec_pch_wake_odl)
#define GPIO_EC_PROCHOT_IN_L	NAMED_GPIO(ec_prochot_in_l)
#define GPIO_ENABLE_BACKLIGHT	NAMED_GPIO(ec_edp_bl_en)
#define GPIO_ENTERING_RW	NAMED_GPIO(ec_entering_rw)
#define GPIO_EN_PP3300_A	NAMED_GPIO(en_pp3300_a)
#define GPIO_EN_PP5000		NAMED_GPIO(en_pp5000_a)
#define GPIO_EN_PPVAR_VCCIN	NAMED_GPIO(en_ppvar_vccin)
#define GPIO_LID_OPEN		NAMED_GPIO(ec_lid_open)
#define GPIO_PCH_PWRBTN_L	NAMED_GPIO(ec_pch_pwr_btn_odl)
#define GPIO_PCH_RSMRST_L	NAMED_GPIO(ec_pch_rsmrst_odl)
#define GPIO_PCH_RTCRST		NAMED_GPIO(ec_pch_rtcrst)
#define GPIO_PCH_SLP_S0_L	NAMED_GPIO(slp_s0_l)
#define GPIO_PCH_SLP_S3_L	NAMED_GPIO(slp_s3_l)
#define GPIO_PCH_DSW_PWROK	GPIO_UNIMPLEMENTED
#define GPIO_PG_EC_ALL_SYS_PWRGD NAMED_GPIO(pg_ec_all_sys_pwrgd)
#define GPIO_PG_EC_DSW_PWROK	NAMED_GPIO(dsw_pwrok)
#define GPIO_PG_EC_RSMRST_ODL	NAMED_GPIO(pg_ec_rsmrst_odl)
#define GPIO_POWER_BUTTON_L	NAMED_GPIO(h1_ec_pwr_btn_odl)
#define GPIO_RSMRST_L_PGOOD	NAMED_GPIO(pg_ec_rsmrst_odl)
#define GPIO_SLP_SUS_L		NAMED_GPIO(slp_sus_l)
#define GPIO_SYS_RESET_L	NAMED_GPIO(sys_rst_odl)
#define GPIO_WP_L		NAMED_GPIO(ec_wp_l)

#ifdef CONFIG_PLATFORM_EC_POWERSEQ
#define POWER_SIGNAL_INT(gpio, edge) \
	GPIO_INT(gpio, edge, power_signal_interrupt)
#define AP_PROCHOT_INT(gpio, edge) \
	GPIO_INT(gpio, edge, throttle_ap_prochot_input_interrupt)
#else
#define POWER_SIGNAL_INT(gpio, edge)
#define AP_PROCHOT_INT(gpio, edge)
#endif

/*
 * Set EC_CROS_GPIO_INTERRUPTS to a space-separated list of GPIO_INT items.
 *
 * Each GPIO_INT requires three parameters:
 *   gpio_signal - The enum gpio_signal for the interrupt gpio
 *   interrupt_flags - The interrupt-related flags (e.g. GPIO_INT_EDGE_BOTH)
 *   handler - The platform/ec interrupt handler.
 *
 * Ensure that this files includes all necessary headers to declare all
 * referenced handler functions.
 *
 * For example, one could use the follow definition:
 * #define EC_CROS_GPIO_INTERRUPTS \
 *   GPIO_INT(NAMED_GPIO(h1_ec_pwr_btn_odl), GPIO_INT_EDGE_BOTH, button_print)
 */
#define EC_CROS_GPIO_INTERRUPTS                                           \
	GPIO_INT(GPIO_AC_PRESENT, GPIO_INT_EDGE_BOTH, extpower_interrupt) \
	GPIO_INT(GPIO_LID_OPEN, GPIO_INT_EDGE_BOTH, lid_interrupt)        \
	GPIO_INT(GPIO_POWER_BUTTON_L, GPIO_INT_EDGE_BOTH,                 \
		 power_button_interrupt)                                  \
	GPIO_INT(GPIO_WP_L, GPIO_INT_EDGE_BOTH, switch_interrupt)         \
	POWER_SIGNAL_INT(GPIO_PCH_SLP_S0_L, GPIO_INT_EDGE_BOTH)           \
	POWER_SIGNAL_INT(GPIO_PCH_SLP_S3_L, GPIO_INT_EDGE_BOTH)           \
	POWER_SIGNAL_INT(GPIO_PG_EC_DSW_PWROK, GPIO_INT_EDGE_BOTH)        \
	POWER_SIGNAL_INT(GPIO_PG_EC_RSMRST_ODL, GPIO_INT_EDGE_BOTH)       \
	POWER_SIGNAL_INT(GPIO_PG_EC_ALL_SYS_PWRGD, GPIO_INT_EDGE_BOTH)    \
	POWER_SIGNAL_INT(GPIO_SLP_SUS_L, GPIO_INT_EDGE_BOTH)              \
	AP_PROCHOT_INT(GPIO_EC_PROCHOT_IN_L, GPIO_INT_EDGE_BOTH)

#endif /* __ZEPHYR_GPIO_MAP_H */
