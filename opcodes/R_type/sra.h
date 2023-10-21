#ifndef SRA_H
#define SRA_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

static inline void execute_SRA(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = (int32_t)cpu.GPR[inst.R_TYPE.rs1] >> cpu.GPR[inst.R_TYPE.rs2];
}

#endif // SRA_H