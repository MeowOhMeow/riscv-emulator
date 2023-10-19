#ifndef ORI_H
#define ORI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define ORI 0x6

static inline void execute_ORI(inst_t inst)
{
    cpu.GPR[inst.I_TYPE.rd] = cpu.GPR[inst.I_TYPE.rs1] | sext(inst.I_TYPE.imm_11_0, 12);
}

#endif // ORI_H