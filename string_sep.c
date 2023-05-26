#include "shell.h"

/**
 * _strtok - separates strings with delims
 * @line: It´s pointer to array we receive in getline.
 * @delim: It´s characters we mark off string in parts.
 * Return: A pointer to the created token
*/

char *_strtok(char *line, char *delim)
{
	int i;
	static char *str;
	char *cpystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*str == delim[i])
			break;
		}
		if (delim[i] == '\0')
			break;
	}
	cpystr = str;
	if (*cpystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (i = 0; delim[i] != '\0'; i++)
		{
			if (*str == delim[i])
			{
				*str = '\0';
				str++;
				return (cpystr);
			}
		}
	}
	return (cpystr);
}

