#ifndef I_TYPE_3_H
#define I_TYPE_3_H

#include "I_TYPE_3/ecall.h"

void execute_I_type_3(inst_t inst)
{
    if (inst.I_TYPE.imm_11_0 == 0)
    {
        execute_ECALL(inst);
    }
    else
    {
        Panic("Unsupported instruction 0x%08x", inst.raw);
    }
}

#endif // I_TYPE_3_H