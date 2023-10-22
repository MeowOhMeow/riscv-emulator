#ifndef SRA_H
#define SRA_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

static inline void execute_SRA(inst_t inst)
{
    bool negative = cpu.GPR[inst.R_TYPE.rs1] & 0x80000000;
    int shift = cpu.GPR[inst.R_TYPE.rs2] & 0x1F;
    if (negative)
    {
        if (shift != 0)
            cpu.GPR[inst.R_TYPE.rd] = sext(cpu.GPR[inst.R_TYPE.rs1] >> shift, 32 - shift);
        else
            cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1];
    }
    else
    {
        cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] >> shift;
    }
}

#endif // SRA_H