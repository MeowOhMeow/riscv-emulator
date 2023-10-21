#ifndef AND_H
#define AND_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define AND 0x7

static inline void execute_AND(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] & cpu.GPR[inst.R_TYPE.rs2];
}

#endif // AND_H