#ifndef LUI_H
#define LUI_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

static inline void execute_LUI(inst_t inst)
{
    cpu.GPR[inst.U_TYPE.rd] = sext(inst.U_TYPE.imm_31_12 << 12, 32);
}

#endif // LUI_H