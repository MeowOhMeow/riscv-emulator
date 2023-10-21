#ifndef BGEU_H
#define BGEU_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define BGEU 0x7

static inline void execute_BGEU(inst_t inst)
{
    if (cpu.GPR[inst.B_TYPE.rs1] >= cpu.GPR[inst.B_TYPE.rs2])
    {
        cpu.PC += sext(inst.B_TYPE.imm_12 << 6 | inst.B_TYPE.imm_10_5, 7);
    }
}

#endif // BGEU_H