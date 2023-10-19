#ifndef SLTIU_H
#define SLTIU_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SLTIU 0x3

static inline void execute_SLTIU(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = cpu.GPR[inst.I_TYPE.rs1] < sext(inst.I_TYPE.imm_11_0, 12);
}

#endif // SLTIU_H