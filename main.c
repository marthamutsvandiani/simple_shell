#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <string.h>
#include <unistd.h>
#include <signal.h>


 
void _sa_handler(int sig);


/**
 * main - Entry point
 * Return: 0 Always Success
 */

int main(void)

{
	char *line = NULL, **u_tokns = NULL;

	int w_len = 0, execFlag = 0;

	size_t line_size = 0;

	ssize_t line_len = 0;

	while (1)
	{
		signal(SIGINT, _sa_handler);
	if (isatty(STDIN_FILENO))
	{

	write(STDOUT_FILENO, "($)", 4);
	}

	line_len = getline(&line, &line_size, stdin);

	if (line_len == -1)
	{
		break;
	}

w_len = count_input(line);

if (line[0] != '\n' && w_len > 0)
{
	u_tokns = tokenize(line, "\t", w_len);
	execFlag = _execBuiltinCommands((const char **)u_tokns, line);
	if (!execFlag)
	{
		char *command_path = find(u_tokns[0]);
        if (command_path && access(command_path, X_OK) == 0)
	{
		execv(command_path, u_tokns);
	}
	else
	{
		perror("./hsh");
	}
	free(command_path);
	}
	frees_tokens(u_tokns);

}
}
free(line);
return (0);
}

/**
 * sa_handler - handles a SIGINT signal (Ctrl+C)
 * @sig : signal number
 */

void _sa_handler(int sig)
{
	(void) sig;

	write(STDOUT_FILENO, "\n($)", 5);

}
