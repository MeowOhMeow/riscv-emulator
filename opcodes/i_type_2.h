#ifndef I_TYPE_2_H
#define I_TYPE_2_H

#include "I_TYPE_2/lb.h"
#include "I_type_2/lh.h"
#include "I_type_2/lw.h"
#include "I_type_2/lbu.h"
#include "I_type_2/lhu.h"

void execute_I_type_2(inst_t inst)
{
    switch (inst.I_TYPE.funct3)
    {
    case LB:
        execute_LB(inst);
        break;
    case LH:
        execute_LH(inst);
        break;
    case LW:
        execute_LW(inst);
        break;
    case LBU:
        execute_LBU(inst);
        break;
    case LHU:
        execute_LHU(inst);
        break;

    default:
        Panic("Unsupported instruction 0x%08x", inst.raw);
        break;
    }
}

#endif // I_TYPE_2_H