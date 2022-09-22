/*
 * include/mach/ctouch.h
 *
 * Copyright (C) 2018 FriendlyARM (www.arm9.net)
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __PLAT_CTOUCH_H__
#define __PLAT_CTOUCH_H__

enum {
	CTP_NONE = 0,
	CTP_AUTO,
	CTP_FT5X06,
	CTP_ITE7260,
	CTP_GOODIX,	  // 1st version
	CTP_GT9XX,    // 2nd version
	CTP_HIMAX,
	CTP_MAX
};

#if defined(CONFIG_MACH_SMDKC110) || defined(CONFIG_MACH_NEOBOT) || defined(CONFIG_MACH_TINYC110)
extern unsigned int mini210_get_ctp(void);
extern void mini210_set_ctp(int type);

static inline int board_get_ctp(void) {
	return mini210_get_ctp();
}

static inline void board_set_ctp(int type) {
	mini210_set_ctp(type);
}

#else

/* Stubs */
#define board_get_ctp()		(CTP_AUTO)
#define board_set_ctp(type)	\
	do { } while (0)

#endif

#endif	// __PLAT_CTOUCH_H__

