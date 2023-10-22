#ifndef SW_H
#define SW_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SW 0x2

static inline void execute_SW(inst_t inst)
{
    uint32_t offset = sext(inst.S_TYPE.imm_11_5 << 5 | inst.S_TYPE.imm_4_0, 12);
    for (int i = 0; i < 4; i++)
    {
        cpu.MEM[cpu.GPR[inst.S_TYPE.rs1] + offset + i] = cpu.GPR[inst.S_TYPE.rs2] >> (8 * i);
    }
}

#endif // SW_H