#ifndef JALR_H
#define JALR_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define JALR 0x0

static inline void execute_JALR(inst_t inst)
{
    uint32_t tmp = cpu.PC + 4;
    cpu.PC = (cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12)) & ~0x1;
    cpu.GPR[inst.I_TYPE.rd] = tmp;
    cpu.PC -= 4;
}

#endif // JALR_H