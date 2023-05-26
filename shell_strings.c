#include "shell.h"

/**
 * _str_length - function returns the length of a string.
 * @string: pointer to input string.
 * Return: returns length of string.
 */

int _str_length(char *string)
{
	int len = 0;

	if (string == NULL)
		return (0);

	while (string[len++] != '\0')
	{
	}
	return (--len);
}

/**
 * _str_duplicate - function duplicates string
 * @string: String to be duplicated
 * Return: returns pointer to the array
 */

char *_str_duplicate(char *string)
{
	char *out_arr;
	int len, i;

	if (string == NULL)
		return (NULL);

	len = _str_length(string) + 1;

	out_arr = malloc(sizeof(char) * len);

	if (out_arr == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < len ; i++)
	{
		out_arr[i] = string[i];
	}

	return (out_arr);
}

/**
 * _str_compare - Compare two strings
 * @string1: String one, or the shorter
 * @string2: String two, or the longer
 * @number: number of characters to be compared, 0 if infinite
 * Return: 1 if the strings are equals,0 if the strings are different
 */

int _str_compare(char *string1, char *string2, int number)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0) /* infinite longitud */
	{
		if (_str_length(string1) != _str_length(string2))
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else /* if there is a number of chars to be compared */
	{
		for (iterator = 0; iterator < number ; iterator++)
		{
			if (string1[iterator] != string2[iterator])
			return (0);
		}
		return (1);
	}
}

/**
 * _str_concat - function concatenates two strings
 * @string1: 1st String to be concatenated
 * @string2: 2nd String to be concatenated
 *
 * Return: returns pointer to the array
 */

char *_str_concat(char *string1, char *string2)
{
	char *out_arr;
	int len1 = 0, len2 = 0;

	if (string1 == NULL)
		string1 = "";
	len1 = _str_length(string1);

	if (string2 == NULL)
		string2 = "";
	len2 = _str_length(string2);

	out_arr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (out_arr == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy of string1 */
	for (len1 = 0; string1[len1] != '\0'; len1++)
		out_arr[len1] = string1[len1];
	free(string1);

	/* copy of string2 */
	for (len2 = 0; string2[len2] != '\0'; len2++)
	{
		out_arr[len1] = string2[len2];
		len1++;
	}

	out_arr[len1] = '\0';
	return (out_arr);
}


/**
 * _str_reverse - function reverses a string.
 *
 * @string: input pointer to string.
 * Return: returns void
 */

void _str_reverse(char *string)
{

	int i = 0, len = _str_length(string) - 1;
	char hold;

	while (i < len)
	{
		hold = string[i];
		string[i++] = string[len];
		string[len--] = hold;
	}
}
