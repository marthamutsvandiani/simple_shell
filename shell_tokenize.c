#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * tokenize :takes out tokens from string
 * @str :the string for the tokenize
 * @del :The delimeter
 * @len : The tokens number
 * Returns : An array of tokens
 */

void remove_new_line(char *str)
{
	int len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] + '\0';
	}
}
int **tokenize(char *str, char *del, int len)
{
	int **tokens = (int **)malloc((len + 1) * sizeof(int *));

	if (tokens == NULL)
	{
	return (NULL);

	}

	remove_new_line(str);

	char *temp_str = _strdup(str);

	char *token = strok(temp_str, del);

	int k = 0;

	while (token != NULL && k < len)
	{
		tokens[k] = (int *)malloc(sizeof(int));
		if (tokens[k] == NULL)
		{
			return (NULL);
		}
		*tokens[k] = atoi(token);
		token = strtok(NULL, del);
		k++;
	}

	tokens[k] = NULL;
	free(temp_str);
	return (tokens);

}
