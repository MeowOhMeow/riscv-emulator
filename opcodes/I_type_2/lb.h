#ifndef LB_H
#define LB_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define LB 0x0

static inline void execute_LB(inst_t inst)
{
    // uint32_t addr = cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12);
    // uint32_t data = *(uint32_t *)&cpu.MEM[addr];
    // cpu.GPR[inst.I_TYPE.rd] = sext(data & 0xff, 8);

    cpu.GPR[inst.I_TYPE.rd] = sext(*(uint32_t *)&cpu.MEM[cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12)] & 0xff, 8);
}

#endif // LB_H