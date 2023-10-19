#ifndef INST_H
#define INST_H

#include <stdint.h>

/* instruction format definition */
typedef union
{
    /*
        I-type Instructions
        We decode the I-type inst. by taking the advantage of Bit-field of struct in C
    */
    struct
    {
        uint32_t opcode : 7;
        uint32_t rd : 5;
        uint32_t func3 : 3;
        uint32_t rs1 : 5;
        uint32_t imm_11_0 : 12;
    } I_TYPE;
    struct
    {
        uint32_t opcode : 7;
        uint32_t rd : 5;
        int32_t imm_31_12 : 20;
    } U_TYPE; // Add a new format LUI AUIPC instruction
    struct
    {
        uint32_t opcode : 7;
        uint32_t imm_20 : 1;
        uint32_t imm_10_1 : 10;
        uint32_t imm_11 : 1;
        uint32_t imm_19_12 : 8;
        uint32_t rd : 5;
    } J_TYPE; // Add a new format for the J-type instructions (jal)
    struct
    {
        uint32_t opcode : 7;
        uint32_t rd : 5;
        uint32_t func3 : 3;
        uint32_t rs1 : 5;
        int32_t imm_11_0 : 12;
    } JALR_TYPE;
    struct
    {
        uint32_t opcode : 7;
        uint32_t imm_12 : 1;
        uint32_t imm_10_5 : 6;
        uint32_t imm_4_1 : 4;
        uint32_t imm_11 : 1;
        uint32_t imm_19_13 : 7;
        int32_t imm_20 : 1;
        uint32_t imm_24 : 1;
        uint32_t rs2 : 5;
        uint32_t rs1 : 5;
        uint32_t func3 : 3;
    } B_TYPE; // Add a new format for the B-type beq instruction
    struct
    {
        uint32_t opcode : 7;
        uint32_t imm_11_5 : 7;
        uint32_t func3 : 3;
        uint32_t rs1 : 5;
        uint32_t rs2 : 5;
        uint32_t imm_4_0 : 5;
        int32_t imm_11_0 : 12;
    } S_TYPE;
    uint32_t raw;
} inst_t;

uint32_t sext(uint32_t imm, int len)
{
    uint32_t mask = 1 << (len - 1);
    return (imm ^ mask) - mask;
}

#endif // INST_H