#ifndef ADD_H
#define ADD_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define ADD_OR_SUB 0x0

static inline void execute_ADD(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] & cpu.GPR[inst.R_TYPE.rs2];
}

#endif // ADD_H