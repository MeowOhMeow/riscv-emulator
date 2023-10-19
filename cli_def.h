#ifndef CLI_FUNCTIONS_H
#define CLI_FUNCTIONS_H

// Command handlers
int cmd_q(const char *args);
int cmd_help(const char *args);
int cmd_tee(const char *args);
int cmd_c(const char *args);
int cmd_si(const char *args);
int cmd_info(const char *args);
int cmd_x(const char *args);

typedef struct
{
    char *name;
    char *description;
    int (*handler)(const char *args);
} Command;

Command commands[] = {
    {"q", "   exit the interactive interface", &cmd_q},
    {"help", "print useful information about supported commands", &cmd_help},
    {"tee", " receive arguments and print them to standard output", &cmd_tee},
    {"c", "   execute instructions until the end", &cmd_c},
    {"si", "  execute one or more instructions", &cmd_si},
    {"info", "print information about registers or PC", &cmd_info},
    {"x", "   print N words starting from BASE_ADDR", &cmd_x},
};

#define CMD_NUM sizeof(commands) / sizeof(Command)

#endif // CLI_FUNCTIONS_H