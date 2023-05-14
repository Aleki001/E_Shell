#include "main.h"
/**
 *main - executes the shell process
 *@ac: argument count
 *@argv: argument variables
 *Return: 0
 */
int main(int ac, char **argv)
{
	size_t bytes;
	ssize_t bytes_read;
	int i;
	char **arguments;
	char *input;

	(void)ac;
	arguments = argv;

	while (1) /*loop for prompt */
	{
		printf("%s", ">>> ");
		bytes_read = getline(&input, &bytes, stdin);

		if (bytes_read == -1)
			break;

		arguments = get_tokens(input); /*getting the tokens*/

		create_childProcess(arguments);

		for (i = 0; arguments[i] != NULL; i++)
			free(arguments[i]);
		free(arguments);

	}

	return (0);

}

/**
 *create_childProcess - creates a child process
 *@arguments: commands to be executed
 *Return: void
 */
void create_childProcess(char **arguments)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("ERROR");
		return;
	}
	else if (pid == 0)
	{
		execute_commands(arguments); /*calling to execute commands*/
		return;
	}
	else
	{
		wait(NULL);
	}
}
