#ifndef SW_H
#define SW_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SW 0x2

static inline void execute_SW(inst_t inst)
{
    for (int i = 0; i < 4; i++)
    {
        cpu.MEM[cpu.GPR[inst.S_TYPE.rs1] + sext(inst.S_TYPE.imm_11_5, 7) + i] = cpu.GPR[inst.S_TYPE.rs2] >> (8 * i);
    }
}

#endif // SW_H