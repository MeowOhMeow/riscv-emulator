#ifndef LH_H
#define LH_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define LH 0x1

static inline void execute_LH(inst_t inst)
{
    // uint32_t addr = cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12);
    // uint32_t data = *(uint32_t *)&cpu.MEM[addr];
    // cpu.GPR[inst.I_TYPE.rd] = sext(data & 0xffff, 16);

    cpu.GPR[inst.I_TYPE.rd] = sext(*(uint32_t *)&cpu.MEM[cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12)] & 0xffff, 16);
}

#endif