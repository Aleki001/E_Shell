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

	cmd_size = strlen(command);

	directory = strtok(path, ":");
	dir_size = strlen(directory);

	while (directory != NULL)
	{
		file_path = malloc(dir_size + cmd_size + 2);
		strcpy(file_path, directory);
		strcat(file_path, "/");
		strcat(file_path, command);

		if (stat(file_path, &buf) == 0)
		{
			path_found = malloc(strlen(file_path) + 1);
			strcpy(path_found, file_path);
			free(file_path);
			return (path_found);
		}
		free(file_path);
		directory = strtok(NULL, ":");
	}
	if (stat(command, &buf) == 0)
	{
		path_found = malloc(strlen(command) + 1);
		strcpy(path_found, command);
		return (path_found);
	}
	return (NULL);
}
