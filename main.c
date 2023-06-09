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
	char *prompt;

	(void)ac;
	input = NULL;
	prompt = ">>> ";
	arguments = argv;

	while (1) /* prompt loop*/
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		bytes_read = getline(&input, &bytes, stdin);/* gets input from user */

		if (bytes_read == -1)/* checks if reached EOF or CTRL + D is pressed */
			break;

		arguments = get_tokens(input, bytes_read, arguments); /*getting the tokens*/

		execute_commands(arguments);
	}
	free(input);

	return (0);
}


/**
 * launch - creates a child process to execute the command
 * @arguments: commands to be executed
 * Return: 1
*/
int launch(char **arguments)
{
	pid_t pid;
	int state;
	char *path = NULL;
	char *command = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (arguments)
		{
			path = arguments[0];
			command = handle_path(path);

			/*executes command using execve function*/
			if (execve(command, arguments, NULL) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (pid < 0)
	{
		perror("Folk Error");
	}
	else
	{
		return (waitpid(pid, &state, 0));
	}

	return (1);
}

