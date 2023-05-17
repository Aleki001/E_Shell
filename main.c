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
	char **arguments;
	char *input;

	(void)ac;
	arguments = argv;

	while (1) /* prompt loop*/
	{
		printf("%s", ">>> ");
		bytes_read = getline(&input, &bytes, stdin);/* gets input from user */

		if (bytes_read == -1)/* checks if reached EOF or CTRL + D is pressed */
			break;

		arguments = get_tokens(input, bytes_read, arguments); /*getting the tokens*/

		create_childProcess(arguments);

	}
	free(input);

	return (0);
}

/**
 *create_childProcess - creates a child process
 *@arguments: commands to be executed
 *Return: void
 */
void create_childProcess(char **arguments)
{
	pid_t pid, p_pid;
	int state;

	pid = fork();

	if (pid == 0)
	{
		execute_commands(arguments);
		exit(0);
	}
	else if (pid > 0)
	{
		p_pid = waitpid(pid, &state, 0);
		if (p_pid == -1)
		{
			perror("Folk Error");
			return;
		}
	}
}
