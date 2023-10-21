#ifndef XOR_H
#define XOR_H

#include "../../cpu.h"
#include "../../inst.h"
#include "../../debug.h"

#define XOR 0x4

static inline void execute_XOR(inst_t inst)
{
    cpu.GPR[inst.R_TYPE.rd] = cpu.GPR[inst.R_TYPE.rs1] ^ cpu.GPR[inst.R_TYPE.rs2];
}

#endif // XOR_H