#ifndef R_TYPE_H
#define R_TYPE_H

#include "R_type/add.h"
#include "R_type/sub.h"
#include "R_type/xor.h"
#include "R_type/or.h"
#include "R_type/and.h"
#include "R_type/sll.h"
#include "R_type/srl.h"
#include "R_type/sra.h"

void execute_R_TYPE(inst_t inst)
{
    switch (inst.R_TYPE.func3)
    {
    case ADD_OR_SUB:
        if (inst.R_TYPE.func7 == 0x0)
            execute_ADD(inst);
        else
            execute_SUB(inst);
        break;
    case XOR:
        execute_XOR(inst);
        break;
    case OR:
        execute_OR(inst);
        break;
    case AND:
        execute_AND(inst);
        break;
    case SLL:
        execute_SLL(inst);
        break;
    case SRL_OR_SRA:
        if (inst.R_TYPE.func7 == 0x0)
            execute_SRL(inst);
        else
            execute_SRA(inst);

    default:
        Panic("Unsupported instruction 0x%08x", inst.raw);
        break;
    }
}

#endif // R_TYPE_H