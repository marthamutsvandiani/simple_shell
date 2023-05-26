#include "shell.h"

/**
 * _print - function writes a array of chars in the standar output
 * @string: pointer to the input array of chars
 * Return: Returns the number of bytes writed or -1
 */

int _print(char *string)
{
	return (write(STDOUT_FILENO, string, _str_length(string)));
}

/**
 * _printe - function writes a array of chars in the standar output
 * @string: pointer to the input array of chars
 * Return: Returns the number of bytes writed or -1
 */

int _printe(char *string)
{
	return (write(STDERR_FILENO, string, _str_length(string)));
}

/**
 * _print_error - function writes a array of chars in the standart error
 * @data: a pointer to the program's data'
 * @errorcode: error code to print
 * Return: Returns the number of bytes writed or -1
 */

int _print_error(int errorcode, data_of_program *data)
{
	char num_string[10] = {'\0'};

	_long_to_string((long) data->exec_counter, num_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(num_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": No such file or directory\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(num_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
