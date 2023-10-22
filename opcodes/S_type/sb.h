#ifndef SB_H
#define SB_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SB 0x0

static inline void execute_SB(inst_t inst)
{
    cpu.MEM[cpu.GPR[inst.S_TYPE.rs1] + sext(inst.S_TYPE.imm_11_5 << 5 | inst.S_TYPE.imm_4_0, 12)] = cpu.GPR[inst.S_TYPE.rs2];
}

#endif // SB_H