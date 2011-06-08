/*
 * This contains functions that are x86 specific and part of the internal
 * implementation.
 */
#ifndef __KVM_X86_IMPL_H
#define	__KVM_X86_IMPL_H

#include <sys/types.h>
#include <vm/page.h>

#include "kvm_host.h"
#include "kvm_x86.h"
#include "kvm_cache_regs.h"

inline void kvm_clear_exception_queue(struct kvm_vcpu *);
inline void kvm_queue_interrupt(struct kvm_vcpu *vcpu, uint8_t vector,
    int soft);
inline void kvm_clear_interrupt_queue(struct kvm_vcpu *vcpu);
inline int kvm_event_needs_reinjection(struct kvm_vcpu *vcpu);
inline int kvm_exception_is_soft(unsigned int nr);
kvm_cpuid_entry2_t *kvm_find_cpuid_entry(struct kvm_vcpu *vcpu,
    uint32_t function, uint32_t index);
inline int is_protmode(struct kvm_vcpu *vcpu);
inline int is_long_mode(struct kvm_vcpu *vcpu);
inline int is_pae(struct kvm_vcpu *vcpu);
inline int is_pse(struct kvm_vcpu *vcpu);
inline int is_paging(struct kvm_vcpu *vcpu);

caddr_t page_address(page_t *page);
extern page_t *alloc_page(size_t, int);
extern uint64_t kvm_va2pa(caddr_t va);
extern page_t *pfn_to_page(pfn_t);
extern int zero_constructor(void *, void *, int);

#define KVM_CPUALL -1

typedef void (*kvm_xcall_t)(void *);
extern void kvm_xcall(processorid_t cpu, kvm_xcall_t func, void *arg);
extern int kvm_xcall_func(kvm_xcall_t func, void *arg);

unsigned long native_read_cr0(void);
#define	read_cr0()	(native_read_cr0())
unsigned long native_read_cr4(void);
#define	read_cr4()	(native_read_cr4())
unsigned long native_read_cr3(void);
#define	read_cr3()	(native_read_cr3())

inline page_t *compound_head(page_t *page);
inline void get_page(page_t *page);
inline unsigned long get_desc_limit(const struct desc_struct *desc);

extern unsigned long get_desc_base(const struct desc_struct *);
uint32_t bit(int);

#endif