#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * shell_free_memory : frees the allocated memory
 * @frees_get_env -access env variables
 * @frees_tokens : frees memory for each token
 * @tokns : tokens
 * Return 0 success, -1 failure
 */

int frees_get_env(char *env_path)

{
	int k;

	for (k = 4; k >= 0; k--)
		env_path--;

	free(env_path);
	return (0);
}
int frees_tokens(char **tokns)
{
	char **temp = tokns;

	if (tokns)
	{
		while (*tokns)
			free(*tokns++);
		free(temp);
		return (0);
	}
	return (-1);
}










