#ifndef BNE_H
#define BNE_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define BNE 0x1

static inline void execute_BNE(inst_t inst)
{
    if (cpu.GPR[inst.B_TYPE.rs1] != cpu.GPR[inst.B_TYPE.rs2])
    {
        cpu.PC += sext(inst.B_TYPE.imm_12 << 12 | inst.B_TYPE.imm_11 << 11 | inst.B_TYPE.imm_10_5 << 5| inst.B_TYPE.imm_4_1 << 1, 13);
    }
}

#endif // BNE_H