#ifndef COMMANDS_H
#define COMMANDS_H

#include "list.h"

/*! @brief Add existing commands to list
*
* Called once on start to put static command definitions in a list
*
* @return list with commands
*/
list SetupCommands(void);

/*! @brief Struct holding info about launch flag
*
* f_ptr is a pointer to the called function
*/
typedef struct
{
    const char* name;
    const char* short_name;
    void (*f_ptr)(list*);
    int args_count;
} command;

/*! @brief Execute command with args
*
* @param[in] cm Pointer to the called command
* @param[in] input_args Pointer to the args list
*/
void ExecuteCommand(command* cm, list* input_args);

/*! @brief Process program launch flags
*
* @param[in] cmds Pointer to the list of all available commands
* @param[in] argc Amount of launch flags
* @param[in] argv Pointer to the array of launch flags
*/
void ProcessArgs(list* cmds, size_t argc ,char** argv);

#endif
