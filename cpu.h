#ifndef CPU_H
#define CPU_H

/* cpu_t definition */
#define MEM_SIZE 0x10000

#include <stdint.h>
#include "inst.h"

typedef struct
{
    uint32_t PC;           // Program Counter
    uint32_t GPR[32];      // General Purpose Registers
    uint8_t MEM[MEM_SIZE]; // Memory
} cpu_t;

/* global variables */
extern bool halt;
extern cpu_t cpu;

#endif // CPU_H