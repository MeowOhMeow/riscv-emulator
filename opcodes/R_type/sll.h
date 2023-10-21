#ifndef SLL_H
#define SLL_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SLL 0x1

static inline void execute_SLL(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] << cpu.GPR[inst.R_TYPE.rs2];
}

#endif // SLL_H