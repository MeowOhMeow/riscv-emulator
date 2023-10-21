#ifndef B_TYPE_H
#define B_TYPE_H

#include "B_type/beq.h"
#include "B_type/bne.h"
#include "B_type/blt.h"
#include "B_type/bge.h"
#include "B_type/bltu.h"
#include "B_type/bgeu.h"

void execute_B_type(inst_t inst)
{
    switch (inst.B_TYPE.funct3)
    {
    case BEQ:
        execute_BEQ(inst);
        break;
    case BNE:
        execute_BNE(inst);
        break;
    case BLT:
        execute_BLT(inst);
        break;
    case BGE:
        execute_BGE(inst);
        break;
    case BLTU:
        execute_BLTU(inst);
        break;
    case BGEU:
        execute_BGEU(inst);
        break;

    default:
        break;
    }
}

#endif // B_TYPE_H