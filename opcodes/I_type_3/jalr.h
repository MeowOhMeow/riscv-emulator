#ifndef JALR_H
#define JALR_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define JALR 0x0

static inline void execute_JALR(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = cpu.PC + 4;
    cpu.PC = (cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12)) & ~0x1;
}

#endif // JALR_H