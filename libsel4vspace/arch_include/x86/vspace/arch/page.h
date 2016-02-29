/*
 * Copyright 2014, NICTA
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(NICTA_BSD)
 */
#ifndef _VSPACE_ARCH_PAGE_H
#define _VSPACE_ARCH_PAGE_H

#include <stddef.h>
#include <utils/attribute.h>
#include <sel4/sel4_arch/constants.h>

/* ordered list of page sizes for this architecture */
static const UNUSED size_t sel4_page_sizes[] = {
    seL4_PageBits,
    seL4_LargePageBits,
};

#define seL4_ARCH_Page_Map             seL4_X86_Page_Map
#define seL4_ARCH_Page_Unmap           seL4_X86_Page_Unmap
#define seL4_ARCH_Page_GetAddress      seL4_X86_Page_GetAddress
#define seL4_ARCH_Page_GetAddress_t    seL4_X86_Page_GetAddress_t
#define seL4_ARCH_PageTable_Map        seL4_X86_PageTable_Map
#define seL4_ARCH_PageTable_Unmap      seL4_X86_PageTable_Unmap
#define seL4_ARCH_ASIDPool_Assign      seL4_X86_ASIDPool_Assign
#define seL4_ARCH_ASIDControl_MakePool seL4_X86_ASIDControl_MakePool
#define seL4_ARCH_PageTableObject      seL4_X86_PageTableObject
#define seL4_ARCH_PageDirectoryObject  seL4_X86_PageDirectoryObject
#define seL4_ARCH_Default_VMAttributes seL4_X86_Default_VMAttributes
#define seL4_ARCH_VMAttributes         seL4_X86_VMAttributes
#define seL4_ARCH_4KPage               seL4_X86_4K
#define seL4_ARCH_Uncached_VMAttributes seL4_X86_CacheDisabled
/* Remap does not exist on all kernels */
#define seL4_ARCH_Page_Remap           seL4_X86_Page_Remap
#define ARCHPageGetAddress             X86PageGetAddress

#endif /* _VSPACE_ARCH_PAGE_H */
