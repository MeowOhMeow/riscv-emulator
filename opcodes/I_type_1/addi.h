#ifndef ADDI_H
#define ADDI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define ADDI 0x0

static inline void execute_ADDI(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = cpu.GPR[inst.I_TYPE.rs1] + sext(inst.I_TYPE.imm_11_0, 12);
}

#endif // ADDI_H