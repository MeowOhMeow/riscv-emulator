#ifndef SRLI_H
#define SRLI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SRLI_OR_SRAI 0x5

static inline void execute_SRLI(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = (uint32_t)cpu.GPR[inst.I_TYPE.rs1] >> (inst.I_TYPE.imm_11_0 & 0x1F);
}

#endif // SRLI_H