#ifndef JAL_H
#define JAL_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

static inline void execute_JAL(inst_t inst)
{
    cpu.GPR[inst.J_TYPE.rd] = cpu.PC + 4;
    cpu.PC += sext((inst.J_TYPE.imm_20 << 20) | (inst.J_TYPE.imm_19_12 << 12) | (inst.J_TYPE.imm_11 << 11) | (inst.J_TYPE.imm_10_1 << 1), 21);
    cpu.PC -= 4;
}

#endif // JAL_H