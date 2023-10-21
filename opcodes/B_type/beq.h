#ifndef BEQ_H
#define BEQ_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define BEQ 0x0

static inline void execute_BEQ(inst_t inst)
{
    if (cpu.GPR[inst.B_TYPE.rs1] == cpu.GPR[inst.B_TYPE.rs2])
    {
        cpu.PC += sext(inst.B_TYPE.imm_12 << 6 | inst.B_TYPE.imm_10_5, 7);
    }
}

#endif // BEQ_H