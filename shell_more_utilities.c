#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _puts :Will print a string to stdout
 * _putchar : writes a single charecter to stdout
 * _strncmp : will compare 2 strings
 * _realloc : resizes a previous allocated memory
 * @a :charecter to print
 * @stri: string to print
 * @stri1 :string 1 to be compared
 * @stri2 :string 2 to be compared
 * @len : comparison limi bytes
 * @ptr :pointer
 * @old_size :the pointer s old size
 * @new_size : the pointer s new size
 * Returns :char,pointer and diff
 */

void _puts(char *stri)
{
while (*stri)
{
	_putchar(*stri);
	stri++;
}
_putchar('\n');
}

int _putchar(char a)
{
	return (write(1, &a, 1));
}

int _strncmp(const char *stri1, const char *stri 2, size_t len)
{
	unsigned int pos = 0;

	int diff = 0;

	while (pos < len)
	{
	if (stri1[pos] == stri2[pos])
	{
		pos++;
		continue;
	}
	else
	{
	diff = stri1[pos] - stri2[pos];
	break
	}
	pos++;
	}
	return (diff);
}
void *_reallc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;

	unsigned int k;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
	nptr = malloc(new_size);

	if (npt == NULL)
	return (NULL);

	return (nptr);
	}
	else
	{
	if (new_size == 0)
	{
	free(ptr);
	return (NULL);
	}
	}
	nptr = malloc(new_size);

	if (nptr == NULL)
		return (NULL);
	for (k = 0; k < old_size && k < new_size; k++)
	{
	nptr[k] = ((char *) ptr)[k];
	}
	free(ptr);
	return (nptr);
}
