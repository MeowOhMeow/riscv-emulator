#ifndef UTIL_H
#define UTIL_H

#include "opcode.h"
#include "inst.h"
#include "stdio.h"

/* util functions */
long fsize(FILE *fp)
{
    long now = ftell(fp);
    Perror(now != -1, "Fail to return the file position");
    int ret = fseek(fp, 0, SEEK_END);
    Perror(ret != -1, "Fail to seek the end of the file");
    long size = ftell(fp);
    Perror(now != -1, "Fail to return the file position");
    ret = fseek(fp, now, SEEK_SET);
    Perror(ret != -1, "Fail to seek the beginning of the file");
    return size;
}

void load_program(char *file_name)
{
    FILE *fp = fopen(file_name, "rb");
    Perror(fp != NULL, "Fail to open the file");
    long size = fsize(fp);
    Assert(size <= MEM_SIZE, "The size of the test program is larger than CPU memory");
    long read = fread(cpu.MEM, 1, size, fp); // load data from file into memory
    Assert(size == read, "Fail to read all contents of the test program");
    fclose(fp);
}

void init(int argc, char *argv[])
{
    /* Check number of argument */
    Assert(argc == 3,
           "There should be 2 arguments...\n Input format should be: ./xxx.elf <entry point addr> <binary file name>");
    char input[100];
    printf("Please input the entry point address (in hex):");
    fgets(input, 100, stdin);
    uint32_t entry_point_addr = strtol(input, NULL, 16);
    char *file_name = argv[2];

    /* initialize of the emulator */
    memset(cpu.MEM, 0, MEM_SIZE); // reset memory with zeros
    cpu.PC = entry_point_addr;    // set PC to entry point address (first instruction of the program)
    for (int i = 0; i < 32; i++)
    {
        cpu.GPR[i] = 0; // Register File (reset to 0)
    }

    cpu.GPR[2] = MEM_SIZE; // set stack pointer to the end of memory

    /* load test program */
    load_program(file_name);
}

void execute_instruction(inst_t instruction)
{
    switch (instruction.raw & 0b1111111)
    {
    case OP_I_TYPE_1:
        execute_I_type_1(instruction);
        break;
    case OP_I_TYPE_2:
        execute_I_type_2(instruction);
        break;
    case OP_I_TYPE_3:
        execute_I_type_3(instruction);
        break;
    case OP_I_TYPE_4:
        execute_I_type_4(instruction);
        break;
    case OP_R_TYPE:
        execute_R_type(instruction);
        break;
    case OP_S_TYPE:
        execute_S_type(instruction);
        break;
    case OP_B_TYPE:
        execute_B_type(instruction);
        break;
    case OP_J_TYPE:
        execute_J_type(instruction);
        break;
    case OP_U_TYPE_1:
        execute_U_type_1(instruction);
        break;
    case OP_U_TYPE_2:
        execute_U_type_2(instruction);
        break;

    default:
        // Handle unknown opcode
        Panic("Unsupported instruction 0x%08x", instruction.raw);
        break;
    }
}

void execute()
{
    Assert(cpu.PC < MEM_SIZE, "PC is out of memory...");
    inst_t instruction = *(inst_t *)(&cpu.MEM[cpu.PC]);
    execute_instruction(instruction);

    cpu.GPR[0] = 0;
    cpu.PC += 4;
}

#endif // UTIL_H