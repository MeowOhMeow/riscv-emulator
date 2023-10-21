#ifndef SRL_H
#define SRL_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define SRL_OR_SRA 0x5

static inline void execute_SRL(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] >> cpu.GPR[inst.R_TYPE.rs2];
}

#endif // SRL_H