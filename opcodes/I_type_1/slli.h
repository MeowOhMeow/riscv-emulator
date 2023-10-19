#ifndef SLLI_H
#define SLLI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SLLI 0x1

static inline void execute_SLLI(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = cpu.GPR[inst.I_TYPE.rs1] << (inst.I_TYPE.imm_11_0 & 0b11111);
}

#endif // SLLI_H