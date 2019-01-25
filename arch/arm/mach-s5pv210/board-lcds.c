/*
 * linux/arch/arm/mach-s5pv210/board-lcds.c
 *
 * Copyright (c) 2011-2017 FriendlyARM (www.arm9.net)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/gpio.h>

#include <plat/fb.h>
#include <plat/ctouch.h>
#include <mach/gpio.h>
#include <mach/regs-gpio.h>

#include <../../../drivers/video/samsung/s3cfb.h>


/* s3cfb configs for supported LCD */

static struct s3cfb_lcd wvga_s430 = {
	.width= 480,
	.height = 800,
	.p_width = 56,
	.p_height = 94,
	.bpp = 24,
	.freq = 60,

	.timing = {
		.h_fp = 64,
		.h_bp = 0,
		.h_sw = 16,
		.v_fp = 32,
		.v_fpe = 1,
		.v_bp = 0,
		.v_bpe = 1,
		.v_sw = 16,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wsvga_x710 = {
	.width = 1024,
	.height = 600,
	.p_width = 154,
	.p_height = 90,
	.bpp = 24,
	.freq = 61,

	.timing = {
		.h_fp = 84,
		.h_bp = 84,
		.h_sw = 88,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 10,
		.v_bpe = 1,
		.v_sw = 20,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wxga_hd700 = {
	.width = 800,
	.height = 1280,
	.p_width = 94,
	.p_height = 151,
	.bpp = 24,
	.freq = 60,

	.timing = {
		.h_fp = 20,
		.h_bp = 20,
		.h_sw = 24,
		.v_fp =  4,
		.v_fpe = 1,
		.v_bp =  4,
		.v_bpe = 1,
		.v_sw =  8,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 0,
		.inv_vsync = 0,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_s70 = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 80,
		.h_bp = 36,
		.h_sw = 10,
		.v_fp = 22,
		.v_fpe = 1,
		.v_bp = 15,
		.v_bpe = 1,
		.v_sw = 8,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_s70d = {
	.width = 800,
	.height = 480,
	.p_width = 154,
	.p_height = 96,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 80,
		.h_bp = 78,
		.h_sw = 10,
		.v_fp = 22,
		.v_fpe = 1,
		.v_bp = 24,
		.v_bpe = 1,
		.v_sw = 8,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd hvga_h43 = {
	.width = 480,
	.height = 272,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp =  5,
		.h_bp = 40,
		.h_sw =  2,
		.v_fp =  8,
		.v_fpe = 1,
		.v_bp =  8,
		.v_bpe = 1,
		.v_sw =  2,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_a97 = {
	.width = 1024,
	.height = 768,
	.p_width = 200,
	.p_height = 150,
	.bpp = 32,
	.freq = 62,

	.timing = {
		.h_fp = 12,
		.h_bp = 12,
		.h_sw = 4,
		.v_fp = 8,
		.v_fpe = 1,
		.v_bp = 8,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_a121 = {
	.width = 1024,
	.height = 768,
	.p_width = 200,
	.p_height = 150,
	.bpp = 32,
	.freq = 63,

	.timing = {
		.h_fp = 32,
		.h_bp = 32,
		.h_sw = 64,
		.v_fp = 8,
		.v_fpe = 1,
		.v_bp = 8,
		.v_bpe = 1,
		.v_sw =  16,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

/* VGAs */
static struct s3cfb_lcd wvga_l80 = {
	.width= 640,
	.height = 480,
	.p_width = 160,
	.p_height = 120,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 35,
		.h_bp = 53,
		.h_sw = 73,
		.v_fp = 3,
		.v_fpe = 1,
		.v_bp = 29,
		.v_bpe = 1,
		.v_sw = 6,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_g10 = {
	.width= 640,
	.height = 480,
	.p_width = 213,
	.p_height = 160,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 0x3c,
		.h_bp = 0x63,
		.h_sw = 1,
		.v_fp = 0x0a,
		.v_fpe = 1,
		.v_bp = 0x22,
		.v_bpe = 1,
		.v_sw = 1,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 0,
		.inv_vsync = 0,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_a56 = {
	.width= 640,
	.height = 480,
	.p_width = 112,
	.p_height = 84,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp = 16,
		.h_bp = 134,
		.h_sw = 10,
		.v_fp = 32,
		.v_fpe = 1,
		.v_bp = 11,
		.v_bpe = 1,
		.v_sw = 2,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_w101 = {
	.width= 1024,
	.height = 600,
	.p_width = 204,
	.p_height = 120,
	.bpp = 32,
	.freq = 60,

	.timing = {
		.h_fp = 40,
		.h_bp = 40,
		.h_sw = 120,
		.v_fp = 10,
		.v_fpe = 1,
		.v_bp = 10,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_w50 = {
	.width= 800,
	.height = 480,
	.p_width = 108,
	.p_height = 64,
	.bpp = 32,
	.freq = 61,

	.timing = {
		.h_fp = 40,
		.h_bp = 40,
		.h_sw = 48,
		.v_fp = 20,
		.v_fpe = 1,
		.v_bp = 20,
		.v_bpe = 1,
		.v_sw = 12,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_w35 = {
	.width= 320,
	.height = 240,
	.p_width = 70,
	.p_height = 52,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp =  4,
		.h_bp = 70,
		.h_sw =  4,
		.v_fp =  4,
		.v_fpe = 1,
		.v_bp = 12,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 0,
		.inv_vsync = 0,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_p35 = {
	.width= 320,
	.height = 240,
	.p_width = 70,
	.p_height = 52,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp =  4,
		.h_bp =  4,
		.h_sw =  4,
		.v_fp =  4,
		.v_fpe = 1,
		.v_bp =  9,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd hvga_p43 = {
	.width = 480,
	.height = 272,
	.p_width = 96,
	.p_height = 54,
	.bpp = 32,
	.freq = 65,

	.timing = {
		.h_fp =  5,
		.h_bp = 40,
		.h_sw =  2,
		.v_fp =  8,
		.v_fpe = 1,
		.v_bp =  9,
		.v_bpe = 1,
		.v_sw =  2,
	},
	.polarity = {
		.rise_vclk = 1,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct s3cfb_lcd wvga_td35 = {
	.width= 240,
	.height = 320,
	.p_width = 52,
	.p_height = 70,
	.bpp = 32,
	.freq = 61,

	.timing = {
		.h_fp =  101,
		.h_bp =  1,
		.h_sw =  5,
		.v_fp =  1,
		.v_fpe = 1,
		.v_bp =  1,
		.v_bpe = 1,
		.v_sw =  10,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

/* HDMI */
static struct s3cfb_lcd hdmi_def = {
	.width = 1920,
	.height = 1080,
	.p_width = 480,
	.p_height = 320,
	.bpp = 32,
	.freq = 62,

	.timing = {
		.h_fp = 12,
		.h_bp = 12,
		.h_sw = 4,
		.v_fp = 8,
		.v_fpe = 1,
		.v_bp = 8,
		.v_bpe = 1,
		.v_sw =  4,
	},
	.polarity = {
		.rise_vclk = 0,
		.inv_hsync = 1,
		.inv_vsync = 1,
		.inv_vden = 0,
	},
};

static struct hdmi_config {
	char *name;
	int width;
	int height;
} mini210_hdmi_config[] = {
	{ "HDMI1080P60",	1920, 1080 },
	{ "HDMI1080I60",	1920, 1080 },
	{ "HDMI1080P30",	1920, 1080 },

	{ "HDMI1080P60D",	 960,  536 },
	{ "HDMI1080I60D",	 960,  536 },
	{ "HDMI1080P30D",	 960,  536 },

	{ "HDMI720P60",		1280,  720 },
	{ "HDMI720P60D",	 640,  360 },

	{ "HDMI576P16X9",	 720,  576 },
	{ "HDMI576P16X9D",	 720,  576 },
	{ "HDMI576P4X3",	 720,  576 },
	{ "HDMI576P4X3D",	 720,  576 },

	{ "HDMI480P16X9",	 720,  480 },
	{ "HDMI480P16X9D",	 720,  480 },
	{ "HDMI480P4X3",	 720,  480 },
	{ "HDMI480P4X3D",	 720,  480 },
};


/* Try to guess LCD panel by kernel command line, or
 * using *W50* as default */

static struct {
	char *name;
	struct s3cfb_lcd *lcd;
	int ctp;
} mini210_lcd_config[] = {
	{ "S430",	&wvga_s430,  1 },
	{ "S70",	&wvga_s70,   1 },
	{ "S701",	&wvga_s70,   CTP_GT9XX   },
	{ "S702",	&wvga_s70,   1 },
	{ "S70D",	&wvga_s70d,  1 },
	{ "X710",	&wsvga_x710, CTP_ITE7260 },
	{ "HD700",	&wxga_hd700, 1 },
	{ "HD702",	&wxga_hd700, CTP_GOODIX  },

	{ "H43",	&hvga_h43,   0 },
	{ "P43",	&hvga_p43,   0 },

	/* TODO: Testing */
	{ "A97",	&wvga_a97,   0 },
	{ "L80",	&wvga_l80,   0 },
	{ "G10",	&wvga_g10,   0 },
	{ "A56",	&wvga_a56,   0 },
	{ "A121",	&wvga_a121,  1 },
	{ "W101",	&wvga_w101,  1 },
	{ "W50",	&wvga_w50,   0 },
	{ "W35",	&wvga_w35,   0 },
	{ "P35",	&wvga_p35,   0 },
	{ "TD35",	&wvga_td35,  0 },

	{ "HDMI",	&hdmi_def,   0 },	/* Pls keep it at last */
};

static int lcd_idx = 0;

static int __init mini210_setup_lcd(char *str)
{
	char *delim;
	int i;

	delim = strchr(str, ',');
	if (delim)
		*delim++ = '\0';

	if (!strncasecmp("HDMI", str, 4)) {
		struct hdmi_config *cfg = &mini210_hdmi_config[0];
		struct s3cfb_lcd *lcd;

		lcd_idx = ARRAY_SIZE(mini210_lcd_config) - 1;
		lcd = mini210_lcd_config[lcd_idx].lcd;

		for (i = 0; i < ARRAY_SIZE(mini210_hdmi_config); i++, cfg++) {
			if (!strcasecmp(cfg->name, str)) {
				lcd->width = cfg->width;
				lcd->height = cfg->height;
				goto __ret;
			}
		}
	}

	for (i = 0; i < ARRAY_SIZE(mini210_lcd_config); i++) {
		if (!strcasecmp(mini210_lcd_config[i].name, str)) {
			lcd_idx = i;
			break;
		}
	}

__ret:
	board_set_ctp(mini210_lcd_config[lcd_idx].ctp);

	printk("Display: %s selected\n", mini210_lcd_config[lcd_idx].name);
	return 0;
}
early_param("lcd", mini210_setup_lcd);


struct s3cfb_lcd *mini210_get_lcd(void)
{
	return mini210_lcd_config[lcd_idx].lcd;
}

void mini210_get_lcd_res(int *w, int *h)
{
	struct s3cfb_lcd *lcd = mini210_lcd_config[lcd_idx].lcd;

	if (w)
		*w = lcd->width;
	if (h)
		*h = lcd->height;

	return;
}
EXPORT_SYMBOL(mini210_get_lcd_res);


#if defined(CONFIG_TOUCHSCREEN_GOODIX) || \
	defined(CONFIG_TOUCHSCREEN_FT5X0X) || \
	defined(CONFIG_TOUCHSCREEN_IT7260) || \
	defined(CONFIG_TOUCHSCREEN_1WIRE)
static unsigned int ctp_type = CTP_AUTO;

static int __init mini210_init_ctp(char *str)
{
	unsigned int val;
	char *p = str, *end;

	val = simple_strtoul(p, &end, 10);
	if (end <= p) {
		return 1;
	}

	if (val < CTP_MAX && mini210_lcd_config[lcd_idx].ctp) {
		ctp_type = val;
	} else if (val == CTP_NONE) {
		ctp_type = CTP_NONE;
	}

	return 1;
}
__setup("ctp=", mini210_init_ctp);

unsigned int mini210_get_ctp(void)
{
	if (mini210_lcd_config[lcd_idx].ctp)
		return ctp_type;
	else
		return CTP_NONE;
}
EXPORT_SYMBOL(mini210_get_ctp);

void mini210_set_ctp(int type)
{
	if (ctp_type == CTP_AUTO && type < CTP_MAX) {
		ctp_type = type;
	}
}
EXPORT_SYMBOL(mini210_set_ctp);
#endif

