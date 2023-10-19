#ifndef R_TYPE_H
#define R_TYPE_H

#include "R_type/add.h"

void execute_R_TYPE(inst_t inst)
{
    switch (inst.R_TYPE.func3)
    {
    case ADD_OR_SUB:
        if (inst.R_TYPE.func7 == 0x0)
            execute_ADD(inst);
        break;

    default:
        Panic("Unsupported instruction 0x%08x", inst.raw);
        break;
    }
}

#endif // R_TYPE_H