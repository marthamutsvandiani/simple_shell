#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * concat_path : concanate [rogramme and path names
 * @path_name :...
 * @prog_name :...
 * Return :Concanated Path and Prog names
 */

char *concat_path(char *path_name, char *prog_name)
{
	int programe_len = 0;
	int path_len = 0;
	int new_size = 0;

	programe_len = _strlen(prog_name);
	path_len = _strlen(path_name);
	new_size = sizeof(char) * (path_len + programe_len + 2);
	path_name = _realloc(path_name, (path_len + 1), new_size);

	if (!path_name)
		return (NULL);

	_strcat(path_name, "/");
	_strcat(path_name, prog_name);

	return (path_name);

}

char *find(char *_name)
{

	int k = 0, num_del = 0;
	struct stat sb;

	if (_name && stat(_name, &sb) != &&_name[0] != '/')

	{

	char *env_path = _getenv("PATH");

	num_del = count_delims(env_path, ":") + 1;

	char **p_tokns = tokenize(env_path, ":", num_del);

	while
	(p_tokns[k])
	{

	free(_name);
	_name = _strup(p_tokns[k];
	frees_get_env(env_path);
	frees_tokens(p_tokns);
	return (_name);
	k++;
	}

	frees_get_env(env_path);
	frees_tokens(p_tokns);
	}

	if (stat(_name, &sb) == 0)
	return (_name);


	free(_name);
	return (NULL);

}

int exec(char *_name, char **options)
{
	pid_t child;
	int status = 0;


	switch (child = fork())
	{
	case -1:
	perror("fork failed");
	return (-1);

	case 0:

	char **environ;

	execve(_name, options, environ);

	default:

	do {
	waitspid(child, &status, WUNTRACED);
	} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);

	}
	return (0);



}


