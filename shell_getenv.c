#include <stdio.h>
#include <stdlib>
#include "shell.h"

/**
 * _getenv : A function to get env variables
 * @name :variable to be found
 * Return :Void
 */

void _getenv(const char *name)
{
	int k = 0;
	char *env_var = NULL;

	while (envron[k])
	{
		env_var = _strdup(environ[k]
		while (*env_var != '=')
		env_var++;

		++env_var;
		return;
	}
	k++;

	}
	return;

}
