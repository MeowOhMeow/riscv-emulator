#ifndef LW_H
#define LW_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define LW 0x2

static inline void execute_LW(inst_t inst)
{
    // uint32_t addr = cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12);
    // uint32_t data = *(uint32_t *)&cpu.MEM[addr];
    // cpu.GPR[inst.I_TYPE.rd] = sext(data, 32);

    cpu.GPR[inst.I_TYPE.rd] = *(uint32_t *)&cpu.MEM[cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12)];
}

#endif // LW_H