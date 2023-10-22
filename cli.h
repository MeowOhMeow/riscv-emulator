#ifndef CLI_H
#define CLI_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cli_def.h"
#include "cpu.h"

/* cli functions */
int cmd_q(const char *args)
{
    exit(0);
}

int cmd_help(const char *args)
{
    if (args == NULL)
    {
        printf("Supported commands:\n");
        for (int i = 0; i < CMD_NUM; i++)
        {
            printf("  %s: %s\n", commands[i].name, commands[i].description);
        }
    }
    else
    {
        for (int i = 0; i < CMD_NUM; i++)
        {
            if (strcmp(args, commands[i].name) == 0)
            {
                printf("%s: %s\n", commands[i].name, commands[i].description);
                return 0;
            }
        }
        printf("Command not found.\n");
    }
    return 0;
}

int cmd_tee(const char *args)
{
    if (args == NULL)
    {
        printf("No arguments received.\n");
    }
    else
    {
        printf("%s\n", args);
    }
    return 0;
}

int cmd_c(const char *args)
{
    halt = false;
    while (!halt)
    {
        execute();
    }
    return 0;
}

int cmd_si(const char *args)
{
    if (args == NULL)
    {
        execute();
    }
    else
    {
        int n = atoi(args);
        for (int i = 0; i < n; i++)
        {
            execute();
        }
    }
    return 0;
}

int cmd_info(const char *args)
{
    if (args == NULL)
    {
        printf("No arguments received. Expected: 'r' or 'pc'\n");
    }
    else
    {
        if (strcmp(args, "r") == 0)
        {
            // Print registers
            printf("Register values:\n");
            for (int i = 0; i < 32; i++)
            {
                printf("%s: x%x\n", reg_name[i], cpu.GPR[i]);
            }
        }
        else if (strcmp(args, "pc") == 0)
        {
            printf("Current PC: 0x%08x\n", cpu.PC);
        }
        else
        {
            printf("Invalid argument. Expected: 'r' or 'pc'\n");
        }
    }
    return 0;
}

int cmd_x(const char *args)
{
    if (args == NULL)
    {
        printf("No arguments received. Expected: 'N' words from 'BASE_ADDR'\n");
    }
    else
    {
    }
    return 0;
}

int handleCommand(const char *input)
{
    char inputCopy[100]; // Create a copy of the input string to avoid modifying the original
    strcpy(inputCopy, input);

    // Tokenize the input string
    char *token = strtok(inputCopy, " ");
    if (token != NULL)
    {
        // Extract the command
        char command[50];
        strcpy(command, token);

        // Extract the arguments (if any)
        char *args = strtok(NULL, "\n");

        for (int i = 0; i < CMD_NUM; i++)
        {
            if (strcmp(command, commands[i].name) == 0)
            {
                return commands[i].handler(args);
            }
        }
        printf("Command not found.\n");
    }
    else
    {
        printf("No command received.\n");
    }

    return 0;
}

#endif // CLI_H
