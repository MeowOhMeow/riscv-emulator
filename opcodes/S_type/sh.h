#ifndef SH_H
#define SH_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SH 0x1

static inline void execute_SH(inst_t inst)
{
    uint32_t offset = sext(inst.S_TYPE.imm_11_5 << 5 | inst.S_TYPE.imm_4_0, 12);
    cpu.MEM[cpu.GPR[inst.S_TYPE.rs1] + offset] = cpu.GPR[inst.S_TYPE.rs2];
    cpu.MEM[cpu.GPR[inst.S_TYPE.rs1] + offset + 1] = cpu.GPR[inst.S_TYPE.rs2] >> 8;
}

#endif // SH_H