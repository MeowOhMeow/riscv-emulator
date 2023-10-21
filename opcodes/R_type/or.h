#ifndef OR_H
#define OR_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define OR 0x6

static inline void execute_OR(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] | cpu.GPR[inst.R_TYPE.rs2];
}

#endif // OR_H