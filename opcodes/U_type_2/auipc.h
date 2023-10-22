#ifndef AUIPC_H
#define AUIPC_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

static inline void execute_AUIPC(inst_t inst)
{
    cpu.GPR[inst.U_TYPE.rd] = cpu.PC + (inst.U_TYPE.imm_31_12 << 12);
}

#endif // AUIPC_H