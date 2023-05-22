#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 *removeNewLine - Removes a newline character from a given string.
 *
 *@strng: The string to modify.
 *
 * Return: A pointer to the modified string.
 */

char *removeNewLine(char *strng)
{
for (int i = 0; strng[i] != '\0'; i++)
{
if (strng[i] == '\n')
{
strng[i] = '\0';
break;
}
}

return (strng);
}
