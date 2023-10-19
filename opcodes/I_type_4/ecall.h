#ifndef ECALL_H
#define ECALL_H

#include <stdio.h>
#include <stdbool.h>
#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define ECALL 0x0

static inline void execute_ECALL(inst_t inst)
{
    // ECALL
    if (cpu.GPR[10] == 0)
    {
        /* stop execution, set up halt signal */
        halt = true;
    }
    else if (cpu.GPR[10] == 1)
    {
        /* put single char to stdout */
        putc(cpu.GPR[11], stdout);
    }
    else
    {
        Panic("Unsupported service request type, value in $a0 is %d", cpu.GPR[10]);
    }
}

#endif // ECALL_H