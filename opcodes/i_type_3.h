#ifndef I_TYPE_3_H
#define I_TYPE_3_H

#include "I_TYPE_3/jalr.h"

void execute_I_type_3(inst_t inst)
{
    switch (inst.I_TYPE.funct3)
    {
    case JALR:
        execute_JALR(inst);
        break;

    default:
        Panic("Unsupported instruction 0x%08x", inst.raw);
        break;
    }
}

#endif // I_TYPE_3_H