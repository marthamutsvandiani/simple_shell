#include "shell.h"

/**
* _get_line - read one line from the prompt.
* @data: struct for the program's data
* Return: reading counting bytes.
*/

int _get_line(data_of_program *data)
{
	char buffer[BUFFER_SIZE] = {'\0'};
	static char *array_of_commands[10] = {NULL};
	static char array_operators[10] = {'\0'};
	ssize_t bytes_read, i = 0;

	/* check if doesnot exist more commands in the array */
	/* and checks the logical operators */
	if (!array_of_commands[0] || (array_operators[0] == '&' && errno != 0) ||
		(array_operators[0] == '|' && errno == 0))
	{
		/*free the memory allocated in the array if it exists */
		for (i = 0; array_of_commands[i]; i++)
		{
			free(array_of_commands[i]);
			array_of_commands[i] = NULL;
		}

		/* read from the file descriptor int to buffer */
		bytes_read = read(data->file_descriptor, &buffer, BUFFER_SIZE - 1);
		if (bytes_read == 0)
			return (-1);

		/* split lines for \n or ; */
		i = 0;
		do {
			array_of_commands[i] = _str_duplicate(_strtok(i ? NULL : buffer, "\n;"));
			/*checks and split for && and || operators*/
			i = _check_logic_ops(array_of_commands, i, array_operators);
		} while (array_of_commands[i++]);
	}

	/*obtains the next command (command 0) and remove it for the array*/
	data->input_line = array_of_commands[0];
	for (i = 0; array_of_commands[i]; i++)
	{
		array_of_commands[i] = array_of_commands[i + 1];
		array_operators[i] = array_operators[i + 1];
	}

	return (_str_length(data->input_line));
}


/**
* _check_logic_ops - checks and split for && and || operators
* @array_commands: array of the commands.
* @i: index in the array_commands to be checked
* @array_operators: array of the logical operators for each previous command
*
* Return: index of the last command in the array_commands.
*/
int _check_logic_ops(char *array_commands[], int i, char array_operators[])
{
	char *temp = NULL;
	int j;

	/* checks for the & char in the command line*/
	for (j = 0; array_commands[i] != NULL  && array_commands[i][j]; j++)
	{
		if (array_commands[i][j] == '&' && array_commands[i][j + 1] == '&')
		{
			/* split the line when chars && was found */
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = _str_duplicate(array_commands[i]);
			array_commands[i + 1] = _str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '&';
			free(temp);
			j = 0;
		}
		if (array_commands[i][j] == '|' && array_commands[i][j + 1] == '|')
		{
			/* split the line when chars || was found */
			temp = array_commands[i];
			array_commands[i][j] = '\0';
			array_commands[i] = _str_duplicate(array_commands[i]);
			array_commands[i + 1] = _str_duplicate(temp + j + 2);
			i++;
			array_operators[i] = '|';
			free(temp);
			j = 0;
		}
	}
	return (i);
}
