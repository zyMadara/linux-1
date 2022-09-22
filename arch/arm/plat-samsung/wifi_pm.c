/*
 * sdio wifi power management API
 */

#include <linux/blkdev.h>
#include <linux/clk.h>
#include <linux/debugfs.h>
#include <linux/device.h>
#include <linux/dma-mapping.h>
#include <linux/err.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/ioport.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/ratelimit.h>
#include <linux/seq_file.h>
#include <linux/slab.h>
#include <linux/stat.h>
#include <linux/delay.h>
#include <linux/irq.h>
#include <linux/bitops.h>
#include <linux/workqueue.h>
#include <mach/gpio-smdkc110.h>
#include <mach/regs-gpio.h>
#include <mach/gpio.h>

#define GPIO_WLAN_EN		S5PV210_GPJ3(7)
#define GPIO_WLAN_HOST_WAKE	S5PV210_GPJ3(6)

int wifi_pm_gpio_ctrl(char *name, int level)
{
	printk(KERN_DEBUG "%s: %d\n", name, level);
	gpio_set_value(GPIO_WLAN_EN, level);
	msleep(50);
	return 0;
}
EXPORT_SYMBOL(wifi_pm_gpio_ctrl);

/*
int get_host_wake_irq(void)
{
	int host_oob_irq = 0;
	int wl_host_wake = GPIO_WLAN_HOST_WAKE;
	host_oob_irq = gpio_to_irq(wl_host_wake);
	if (IS_ERR_VALUE(host_oob_irq)) {
		printk("map gpio [%d] to virq failed, errno = %d\n",wl_host_wake, host_oob_irq);
		return 0;
	}
	printk("wifi: gpio [%d] map to virq [%d] ok\n",wl_host_wake, host_oob_irq);

	return host_oob_irq;
}
EXPORT_SYMBOL(get_host_wake_irq);
*/
