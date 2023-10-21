#ifndef SH_H
#define SH_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SH 0x1

static inline void execute_SH(inst_t inst)
{
    cpu.MEM[cpu.GPR[inst.S_TYPE.rs1] + sext(inst.S_TYPE.imm_11_5, 7)] = cpu.GPR[inst.S_TYPE.rs2];
    cpu.MEM[cpu.GPR[inst.S_TYPE.rs1] + sext(inst.S_TYPE.imm_11_5, 7) + 1] = cpu.GPR[inst.S_TYPE.rs2] >> 8;
}

#endif // SH_H