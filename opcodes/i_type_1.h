#ifndef I_TYPE_1_H
#define I_TYPE_1_H

#include "I_TYPE_1/addi.h"
#include "I_TYPE_1/xori.h"
#include "I_TYPE_1/ori.h"
#include "I_TYPE_1/andi.h"
#include "I_TYPE_1/slli.h"
#include "I_TYPE_1/srli.h"
#include "I_TYPE_1/srai.h"
#include "I_TYPE_1/slti.h"
#include "I_TYPE_1/sltiu.h"

void execute_I_type_1(inst_t inst)
{
    switch (inst.I_TYPE.func3)
    {
    case ADDI:
        execute_ADDI(inst);
        break;
    case XORI:
        execute_XORI(inst);
        break;
    case ORI:
        execute_ORI(inst);
        break;
    case ANDI:
        execute_ANDI(inst);
        break;
    case SLLI:
        execute_SLLI(inst);
        break;
    case SRLI_OR_SRAI:
        if (inst.I_TYPE.imm_11_0 & 0b111111100000 == 0x0)
            execute_SRLI(inst);
        else
            execute_SRAI(inst);
        break;
    case SLTI:
        execute_SLTI(inst);
        break;
    case SLTIU:
        execute_SLTIU(inst);
        break;
    default:
        // Handle unknown opcode
        Panic("Unsupported instruction 0x%08x", inst.raw);
        break;
    }
}

#endif // I_TYPE_1_H