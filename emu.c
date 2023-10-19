#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "debug.h"
#include "util.h"
#include "cli.h"

/* global variables */
bool halt = false;
cpu_t cpu;

/* main function */
int main(int argc, char *argv[])
{
    /* initialize */
    init(argc, argv);

    /* running */
    while (true)
    {
        char input[100];
        printf(">> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0; // Remove the newline character from input
        handleCommand(input);
    }
}
