
#include <linux/kallsyms.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 1, 0)
int (*_bk_set_memory_rw)(unsigned long addr, int numpages);

int _bk_set_memory_rw_fallback(unsigned long addr, int numpages)
{
	return 0;
}
#endif

static void *bk_lookup(const char *symbol, void *fallback)
{
	unsigned long addr;
	void *ret = NULL;

	addr = kallsyms_lookup_name(symbol);
	if (addr == 0) {
		ret = fallback;
		if (ret != NULL)
			printk_once(KERN_WARNING "Warning: fail to get symbol %s, replace it with fallback\n", symbol);
		else {
			printk_once(KERN_ERR "Error: fail to get symbol %s\n", symbol);
			BUG();
		}
	} else {
		ret = (void *)addr;
	}

	return ret;
}

void bk_init(void)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 1, 0)
	_bk_set_memory_rw = bk_lookup("set_memory_rw", _bk_set_memory_rw_fallback);
#endif
}
