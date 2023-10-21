#ifndef SLT_H
#define SLT_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SLT 0x2

static inline void execute_SLT(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = (int32_t)cpu.GPR[inst.R_TYPE.rs1] < (int32_t)cpu.GPR[inst.R_TYPE.rs2];
}

#endif // SLT_H