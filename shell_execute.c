#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * concat_path : concanate program and path names
 * @path_name :pointer to path name string
 * @prog_name :pointer to program name string
 * Return :Concanated Path and program names
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
/**
 * find - finds the location of a command in PATH directories
 * @_name : pointer to command string
 *
 * Return : path to command or NULL if not found
 */


char *find(char *_name)
{

	int k = 0, num_del = 0;

	struct stat sb;

	char *env_path = NULL, **p_tokns = NULL, *temp = NULL, *ret_val = NULL;

	if (_name && stat(_name, &sb) != 0 && _name[0] != '/')

	{

	env_path = getenv("PATH");

	num_del = count_delims(env_path, ":") + 1;

	p_tokns = (char **)tokenize(env_path, ":", num_del);
	
	while (p_tokns[k])

	{
	 temp = strdup(p_tokns[k]);
	 ret_val = concat_path(temp, _name);

	 if (stat(ret_val, &sb) == 0)
	 {
	 
	 free(temp);
	free(env_path);
	frees_tokens(p_tokns);
	return (ret_val);
	}

	k++;
	free(temp);
	free(ret_val);

	}

	free(env_path);
	frees_tokens(p_tokns);
 }

	if (stat(_name, &sb) == 0)
{
	ret_val = strdup(_name);
	return (ret_val);
}



	return (NULL);

}

/**
 * exec - executes a command with arguments
 *
 * @_name : pointer to command string
 * @options : array of pointers to option strings
 *
 * Return : 0 on success, -1 on failure
 */

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

		execve(_name, options, NULL);
		perror("execve failed");
		exit(EXIT_FAILURE);

	default:

	do {
	waitpid(child, &status, WUNTRACED);
	} while (WIFEXITED(status) && !WIFSIGNALED(status));

	}
	return (0);



}


