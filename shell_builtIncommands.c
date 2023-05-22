#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
*execBuiltInCommands:Executes a built-in command.
*@param tokens: An array of strings representing the command and its arguments.
*@param line: A string containing the original input line entered by the user.
*@return 1 if the command is a built-in command, 0 otherwise.
*/

int execBuiltInCommands(char **tokens, char *line)
{
int i = 0;
char *ListBuiltinCmds[] = {"exit", "cd", "help", "env", NULL};

while (ListBuiltinCmds[i])
{
if (_strcmp(tokens[0], ListBuiltinCmds[i]) == 0)
{
if (i == 0)
{
_handle_exit(tokens, line);
return (1);
}
else if (i == 1)
{
chdir(tokens[1]);
return (1);
}
else if (i == 2)
{
_open_help();
return (1);
}
else if (i == 3)
{
_print_env();
return (1);
}
}
i++;
}

return (0);
}
