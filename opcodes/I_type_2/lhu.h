#ifndef LHU_H
#define LHU_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define LHU 0x5

static inline void execute_LHU(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = *(uint32_t *)&cpu.MEM[cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12)] & 0xffff;
}

#endif // LHU_H