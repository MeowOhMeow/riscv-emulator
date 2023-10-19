#ifndef XORI_H
#define XORI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define XORI 0x4

static inline void execute_XORI(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = cpu.GPR[inst.I_TYPE.rs1] ^ sext(inst.I_TYPE.imm_11_0, 12);
}

#endif // XORI_H
