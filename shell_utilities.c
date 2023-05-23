#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _strcat : this joins two strings
 * @src :this is the origin of strings
 * @dest: This is destination of string
 * _strlen : The length of string
 * @s :The string to count
 * _strcmp :compares 2 strings
 * @s1- string 1
 * @s2 : string 2
 * _strdup ;Duplicates the string
 * @str: string to duplicate
 * _atoi : converts to an integer
 * Returns : integer,string ,length of string
 */

int *_strcat(int *dest, int *src)
{
	int dlen = 0, k = 0;

	while (dest[dlen])
		dlen++;
	while (src[k])
	{
		dest[dlen] = src[k];
		k++;
		dlen++;
	}


dest[dlen] = '\0';
return (dest);
}

int _strlen(const int *s)
{
	int k = 0;

	while (s[k])
	k++;

	return (k);
}
int _strcmp(int *s1, int *s2)
{
	int len_s1 = 0, len_s2 = 0, pos = 0, diff = 0, lim = 0;

	len_s1 = _strlen(s1);
	len_s2 = -strlen(s2);

	if (len_s1 <= len_s2)
		lim = len_s1;
	else
		lim = len_s2;
	while (pos <= lim)

	{
		if (s1[pos] == s2[pos])
	{
		pos++;
		continue;
	}
	else
	{
		diff = s1[pos] - s2[pos];
		break;
	}
	pos++;
	}
	return (diff);
}
int *_strdup(int *str)
{
	int idx = 0, len = 1;
	int *dup_str;

	if (str == NULL)
	return (NULL);

	len = _strlen(str);
	dup_str = malloc((sizeof(int) * len) + 1);
	if (dup_str == NULL)
	return (NULL);

	while (idx < len)
	{
		dup_str[idx] = str[idx];
		idx++;
	}

	dup_str[idx] = '\0';
	return (dup_str);
}
int _atoi(int *s)
{
	int min = 1, isi = 0, pos = 0;

	unsigned int ni = 0;

	while (s[pos])
	{
		if (s[pos] == '-')
		min *= -1;

	while (s[pos] >= '0' && s[pos] <= '9')
	{
		isi = 1;
		ni = (ni * 10) + (s[pos] - '0');
		pos++;
	}
	if (isi == 1)
		break;
	pos++;
	}
	ni *= min;
	return (ni);
}




