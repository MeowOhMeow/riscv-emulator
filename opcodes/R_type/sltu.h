#ifndef SLTU_H
#define SLTU_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SLTU 0x3

static inline void execute_SLTU(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] < cpu.GPR[inst.R_TYPE.rs2];
}

#endif // SLTU_H