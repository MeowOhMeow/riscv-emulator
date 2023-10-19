#ifndef I_TYPE_4_H
#define I_TYPE_4_H

#include "I_type_4/ecall.h"

void execute_I_type_4(inst_t inst)
{
    switch (inst.I_TYPE.imm_11_0)
    {
    case ECALL:
        execute_ECALL(inst);
        break;

    default:
        Panic("Unsupported instruction 0x%08x", inst.raw);
        break;
    }
}

#endif // I_TYPE_4_H