#include "shell.h"

/**
 * _builtins_list - search for match and _execute the associate builtin
 * @data: struct for the program's data
 * Return: Returns the return of the function _executed is there is a match,
 * otherwise returns -1.
 **/
int _builtins_list(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", _builtin_exit},
		{"help", _builtin_help},
		{"cd", _builtin_cd},
		{"alias", _builtin_alias},
		{"env", _builtin_env},
		{"setenv", _builtin_set_env},
		{"unsetenv", _builtin_unset_env},
		{NULL, NULL}
	};

/*walk through the structure*/
	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
/*if there is a match between the given command and a builtin,*/
		if (_str_compare(options[iterator].builtin, data->command_name, 0))
		{
/*_execute the function, and return the return value of the function*/
			return (options[iterator].function(data));
		}
/*if there is no match return -1 */
	}
	return (-1);
}

