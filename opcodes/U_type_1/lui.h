#ifndef LUI_H
#define LUI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

static inline void execute_LUI(inst_t inst)
{
    cpu.GPR[inst.U_TYPE.rd] = inst.U_TYPE.imm_31_12 << 12;
}

#endif // LUI_H