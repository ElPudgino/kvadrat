#include <stdio.h>
#include "list.h"
#include "commands.h"
#include "tools.h"
#include <cstring>
#include "commands_def.h"

void ExecuteCommand(command* cm, list* cm_args)
{
    cm -> f_ptr(cm_args);
}

list SetupCommands(void)
{
    list Commands;
    ListInit(Commands, command);

    ListAdd(Commands, Solve);

    ListAdd(Commands, Coef);

    ListAdd(Commands, File);

    ListAdd(Commands, Test);

    ListAdd(Commands, Scam);

    return Commands;
}


#define CheckForParam(prm) CompareStrings(argv[1+index], prm)

//               list of all commands
void ProcessArgs(list* cmds, size_t argc ,char** argv)
{

    list CommandArgs;
    ListInit(CommandArgs, char*);
    int ArgsToRead = -1;
    command* cmd = NULL;

    size_t index = 0;
    for (index = 0; index < (argc-1); index += 1)
    {
        if (ArgsToRead > 0)
        {
            ListAdd(CommandArgs, argv[1+index]);
            ArgsToRead -= 1;
            continue;
        }
        if (ArgsToRead == 0)
        {
            ExecuteCommand(cmd, &CommandArgs);
            ArgsToRead -= 1;
        }


        size_t c_index = 0;
        int found_command = 0;

        for (c_index = 0; c_index < cmds->count; c_index += 1)
        {
            cmd = &ListGet(*cmds, c_index, command);

            if (CheckForParam(cmd->name) ||
                CheckForParam(cmd->short_name))
            {
                found_command = 1;
                break;
            }
        }

        if (found_command)
        {
            ListBegone(CommandArgs);
            ListInit(CommandArgs, char*);

            ArgsToRead = cmd->args_count;
        }

    }

    if (ArgsToRead == 0)
    {
        ExecuteCommand(cmd, &CommandArgs);
        ArgsToRead -= 1;
    }
    ListBegone(CommandArgs);
}
/*
-s --solve
-t --tests
-f --file
-c --coef
*/
