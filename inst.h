#ifndef INST_H
#define INST_H

#include <stdint.h>

/* instruction format definition */
typedef union
{
    struct
    {
        uint32_t opcode : 7;
        uint32_t rd : 5;
        uint32_t funct3 : 3;
        uint32_t rs1 : 5;
        uint32_t rs2 : 5;
        int32_t funct7 : 7;
    } R_TYPE;

    struct
    {
        uint32_t opcode : 7;
        uint32_t rd : 5;
        uint32_t funct3 : 3;
        uint32_t rs1 : 5;
        int32_t imm_11_0 : 12;
    } I_TYPE;

    struct
    {
        uint32_t opcode : 7;
        uint32_t imm_4_0 : 5;
        uint32_t funct3 : 3;
        uint32_t rs1 : 5;
        uint32_t rs2 : 5;
        int32_t imm_11_5 : 7;
    } S_TYPE;

    struct
    {
        uint32_t opcode : 7;
        uint32_t imm_11 : 1;
        uint32_t imm_4_1 : 4;
        uint32_t funct3 : 3;
        uint32_t rs1 : 5;
        uint32_t rs2 : 5;
        uint32_t imm_10_5 : 6;
        int32_t imm_12 : 1;
    } B_TYPE;

    struct
    {
        uint32_t opcode : 7;
        uint32_t rd : 5;
        int32_t imm_31_12 : 20;
    } U_TYPE;

    struct
    {
        uint32_t opcode : 7;
        uint32_t rd : 5;
        uint32_t imm_19_12 : 8;
        uint32_t imm_11 : 1;
        uint32_t imm_10_1 : 10;
        int32_t imm_20 : 1;
    } J_TYPE;

    uint32_t raw;
} inst_t;

uint32_t sext(uint32_t imm, int len)
{
    // truncate imm
    imm = imm & ((1U << len) - 1);
    // sign extend
    uint32_t mask = 1U << (len - 1);
    return (imm ^ mask) - mask;
}

#endif // INST_H