#include "main.h"
/**
 *handle_path - gets the location of a command
 *@command: shell command
 *Return: path of the command otherwise null
 */
char *handle_path(char *command)
{
	struct stat buf;
	int cmd_size, dir_size;
	char *path, *directory, *path_found, *file_path;

	path = getenv("PATH");

	if (path == NULL)
		return (NULL);

	cmd_size = _strlen(command);

	directory = strtok(path, ":");
	dir_size = _strlen(directory);

	while (directory != NULL)
	{
		file_path = malloc(dir_size + cmd_size + 2);
		_strcpy(file_path, directory);
		_strcat(file_path, "/");
		_strcat(file_path, command);

		if (stat(file_path, &buf) == 0)
		{
			path_found = malloc(_strlen(file_path) + 1);
			_strcpy(path_found, file_path);
			free(file_path);
			return (path_found);
		}
		free(file_path);
		directory = strtok(NULL, ":");
	}
	if (stat(command, &buf) == 0)
	{
		path_found = malloc(_strlen(command) + 1);
		_strcpy(path_found, command);
		return (path_found);
	}
	return (NULL);
}
