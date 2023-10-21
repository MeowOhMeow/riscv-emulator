#ifndef SLTI_H
#define SLTI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SLTI 0x2

static inline void execute_SLTI(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = (int32_t)cpu.GPR[inst.I_TYPE.rs1] < (int32_t)sext(inst.I_TYPE.imm_11_0, 12);
}

#endif // SLTI_H