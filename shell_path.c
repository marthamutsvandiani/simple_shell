#include "shell.h"

int _check_file(char *full_path);

/**
 * _find_program - find a program in path
 * @data: a pointer to the program's data
 * Return: 0 if success, errcode otherwise
 */

int _find_program(data_of_program *data)
{
	int i = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	/**if is a full_path or an executable in the same path */
	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (_check_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = _str_concat(_str_duplicate("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = __tokenize_path(data);/* search in the PATH */

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}
	for (i = 0; directories[i]; i++)
	{/* appends the function_name to path */
		directories[i] = _str_concat(directories[i], data->tokens[0]);
		ret_code = _check_file(directories[i]);
		if (ret_code == 0 || ret_code == 126)
		{/* the file was found, is not a directory and has _execute permisions*/
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = _str_duplicate(directories[i]);
			 _free_array_of_pointers(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	 _free_array_of_pointers(directories);
	return (ret_code);
}

/**
 * __tokenize_path - _tokenize the path in directories
 * @data: a pointer to the program's data
 * Return: array of path directories
 */

char **__tokenize_path(data_of_program *data)
{
	int i = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	/* get the PATH value*/
	PATH = _env_get_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{/*path not found*/
		return (NULL);
	}

	PATH = _str_duplicate(PATH);

	/* find the number of directories in the PATH */
	for (i = 0; PATH[i]; i++)
	{
		if (PATH[i] == ':')
			counter_directories++;
	}

	/* reserve space for the array of pointers */
	tokens = malloc(sizeof(char *) * counter_directories);

	/*_tokenize and duplicate each token of path*/
	i = 0;
	tokens[i] = _str_duplicate(_strtok(PATH, ":"));
	while (tokens[i++])
	{
		tokens[i] = _str_duplicate(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * _check_file - checks if exists a file, if it is not a dairectory and
 * if it has excecution permisions for permisions.
 * @full_path: pointer to the full file name
 * Return: 0 on success, or error code if it exists.
 */

int _check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/*if not exist the file*/
	errno = 127;
	return (127);
}

