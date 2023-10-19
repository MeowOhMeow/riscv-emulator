#ifndef ANDI_H
#define ANDI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define ANDI 0x7

static inline void execute_ANDI(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = cpu.GPR[inst.I_TYPE.rs1] & sext(inst.I_TYPE.imm_11_0, 12);
}

#endif // ANDI_H