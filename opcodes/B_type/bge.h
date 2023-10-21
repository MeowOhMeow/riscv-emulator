#ifndef BGE_H
#define BGE_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define BGE 0x5

static inline void execute_BGE(inst_t inst)
{
    if ((int32_t)cpu.GPR[inst.B_TYPE.rs1] >= (int32_t)cpu.GPR[inst.B_TYPE.rs2])
    {
        cpu.PC += sext(inst.B_TYPE.imm_12 << 6 | inst.B_TYPE.imm_10_5, 7);
    }
}

#endif // BGE_H