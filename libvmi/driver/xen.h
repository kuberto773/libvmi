/*
 * The LibVMI Library is an introspection library that simplifies access to 
 * memory in a target virtual machine or in a file containing a dump of 
 * a system's physical memory.  LibVMI is based on the XenAccess Library.
 *
 * Copyright (C) 2010 Sandia National Laboratories
 * Author: Bryan D. Payne (bpayne@sandia.gov)
 */

#ifdef ENABLE_XEN
#include <xenctrl.h>

typedef struct xen_instance{
    int xc_handle;          /**< handle to xenctrl library (libxc) */
    unsigned long domainid; /**< domid that we are accessing */
    int xen_version;        /**< version of Xen libxa is running on */
    int hvm;                /**< nonzero if HVM memory image */
    xc_dominfo_t info;      /**< libxc info: domid, ssidref, stats, etc */
    unsigned long *live_pfn_to_mfn_table;
    unsigned long nr_pfns;
} xen_instance_t;

#endif /* ENABLE_XEN */

status_t xen_init (vmi_instance_t vmi);
void xen_destroy (vmi_instance_t vmi);
unsigned long xen_get_domainid (vmi_instance_t vmi);
void xen_set_domainid (vmi_instance_t vmi, unsigned long domainid);
status_t xen_get_domainname (vmi_instance_t vmi, char **name);
status_t xen_get_memsize (vmi_instance_t vmi, unsigned long *size);
status_t xen_get_vcpureg (vmi_instance_t vmi, reg_t value, registers_t reg, unsigned long vcpu);