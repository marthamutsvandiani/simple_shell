#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _count_input: will count the words from user
 * @stri :the string to count the words
 * Returns : The count of words in string
 */

int _count_input(char *stri)
{
	int k = 0, wc = 0, state = 0;

	while (stri[k])
	{
	if (stri[k] == '' || stri[k] == '\n' || stri[k] == '\t')
		state = 0;
	else if (state == 0)
	{
	state = 1;

	wc++;
	}

	k++;
	}

	return (wc);

}

int _count_delims(char *stri, char *del)
{
	int k = 0, l = 0, wc = 0;

	while (del[k])
	{
	l = 0;
	while (stri[l])
	{
	if (str[l] == del[k]
	wc++;
	l++
	}
	k++;

	}
	return (wc);
}


