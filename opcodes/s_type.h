#ifndef S_TYPE_H
#define S_TYPE_H

#include "S_type/sb.h"

void execute_S_TYPE(inst_t inst)
{
    switch (inst.S_TYPE.funct3)
    {
    case SB:
        execute_SB(inst);
        break;

    default:
        break;
    }
}

#endif // S_TYPE_H