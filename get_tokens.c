#include "main.h"
/**
 *get_tokens - splits the string into tokens
 *@input:  string to be split
 *Return: tokens
 */
char **get_tokens(char *input)
{
	char *token;
	char **argv = NULL;
	const char *delim = " \n";
	int i, count_token = 0;

	/*get no of tokens*/
	token = strtok(input, delim);
	for (; token != NULL;)
	{
		count_token++;
		token = strtok(NULL, delim);
	}

	/* allocate space for all tokens*/
	argv = malloc(sizeof(char *) * (count_token + 1));

	/*store evry token in argv array*/
	token = strtok(input, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[count_token] = NULL;

	return (argv);
}

/**
 *execute_commands - function executes the commands
 *@arguments: tokens
 *Return: void
 */
void execute_commands(char **arguments)
{
	char *path = NULL;
	char *command = NULL;

	if (arguments)
	{
		path = arguments[0];
		command = handle_path(path);

		/*executes command using execve function*/
		if (execve(command, arguments, NULL) == -1)
			perror("./shell");

	}
}
