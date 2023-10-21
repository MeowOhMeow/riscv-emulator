#ifndef SUB_H
#define SUB_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

static inline void execute_SUB(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] - cpu.GPR[inst.R_TYPE.rs2];
}

#endif  // SUB_H