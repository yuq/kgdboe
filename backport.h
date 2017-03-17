#ifndef _YUQ_BACKPORT_H_
#define _YUQ_BACKPORT_H_

#include <linux/version.h>
#include <asm/cacheflush.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 1, 0)
extern int (*_bk_set_memory_rw)(unsigned long addr, int numpages);
#endif

static inline int bk_set_memory_rw(unsigned long addr, int numpages)
{
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 1, 0)
	return _bk_set_memory_rw(addr, numpages);
#else
	return set_memory_rw(addr, numpages);
#endif
}

void bk_init(void);

#endif
