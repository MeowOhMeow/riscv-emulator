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

char **reg_name = (char *[]){"zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
                             "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
                             "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
                             "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

#endif // CPU_H