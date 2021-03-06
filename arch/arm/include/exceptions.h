#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H

#include <stdint.h>
#include <compiler.h>

static inline void arch_enable_interrupts()
{ __asm__ volatile ("cpsie if"); }

static inline void arch_disable_interrupts()
{ __asm__ volatile ("cpsid if"); }

typedef struct
{
    uint32_t r[4], r12, lr;
    uint32_t pc, spsr;
} irq_frame_t;

typedef struct
{
    uint32_t r[13], lr;
    uint32_t pc, spsr;
} exception_frame_t;

#endif /* _EXCEPTIONS_H */
