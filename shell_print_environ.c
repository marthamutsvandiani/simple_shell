#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _print_env : Inspects the current environment variables
 * Returns 0 success, -1 failure
 */

int _print_env(void)
{
	int k = 0, l = 0;

	while (environ[k])
	{
		l = 0;

	while (environ[k][l])
	{
		_putchar(environ[k][l]);
		l++;
	}
	if (l != 0)
		_putchar('\n');
	k++;
	}
	return (0);
}
