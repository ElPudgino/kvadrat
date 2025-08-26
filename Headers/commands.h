#ifndef COMMANDS_H
#define COMMANDS_H

#include "list.h"

list SetupCommands(void);

typedef struct
{
    const char* name;
    const char* short_name;
    void (*f_ptr)(list*);
    int args_count;
} command;

void ExecuteCommand(command* cm, list* parsed_args);

void ProcessArgs(list* cmds, size_t argc ,char** argv);

#endif
