#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * main - Entry point
 * code handles how the shell exits
 * @line : new line
 * @u_tokns: seperates input line into diff tokens
 * _handle_exit :implements how the shell exits
 * Returns : an integer
 */

int _handle_exit(char **u_tokns, char *line)

{
	int status;

	if (u_tokns[1] == NULL(!_strcmp(u_tokns[1], "0")))
	{
		frees_tokens(u_tokns);
		free(line);
		exit(0);
	}
	status = _atoi(u_tokns[1]);

	if (status != 0)

	{

	frees_tokens(u_tokns);
	free(line);
	exit(status);

	}

	else

	{
		 print_error("exit, illegal number !");
		 _puts(u_tokns[1]);
		 _puts("\n");
		 exit(2);
	}

	 frees_tokens(u_tokns);
	 free(line);
	return (EXIT_SUCCESS);
}
