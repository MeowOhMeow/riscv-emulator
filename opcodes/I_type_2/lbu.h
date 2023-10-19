#ifndef LBU_H
#define LBU_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define LBU 0x4

static inline void execute_LBU(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = *(uint32_t *)&cpu.MEM[cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12)] & 0xff;
}

#endif // LBU_H