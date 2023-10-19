#ifndef SRAI_H
#define SRAI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

static inline void execute_SRAI(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = (cpu.GPR[inst.I_TYPE.rs1] >> (inst.I_TYPE.imm_11_0 & 0b11111)) | (cpu.GPR[inst.I_TYPE.rs1] & 0b10000);
}

#endif // SRAI_H