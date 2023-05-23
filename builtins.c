#include "main.h"
/**
 * exit_builtin - exit the shell when invoked
 * @arguments: commands
 * Return: exit status
 */
int exit_builtin(char **arguments)
{
	int status;

	if (arguments[1])
	{
		status = atoi(arguments[1]);
		exit(status);
	}
	else
	{
		exit(0);
	}
}

/**
 * help_builtin - displays help
 * @arguments: commands
 * Return: 1 otherwise 0
 */
int help_builtin(char **arguments)
{
	printf("This is help!!");
	return (1);
}

/**
 * cd_builtin - changes directory when invoked
 * @arguments: commands
 * Return: 1 otherwise 0
 */
int cd_builtin(char **arguments)
{
	printf("This is cd");
	return (1);
}

/**
 * execute_commands - executes commands passed through it
 * @arguments: commands
 * Return: 1
 */
int execute_commands(char **arguments)
{
	int i = 0;
	builtin_command builtins[] = {
		{"exit", exit_builtin},
		{"cd", cd_builtin},
		{"help", help_builtin}
	};

	if (arguments[0] == NULL)
		return (1);
	while (i < 3)
	{
		if (strcmp(arguments[0], builtins[i].name) == 0)
			return (builtins[i].function(arguments));
		i++;
	}

	return (launch(arguments));
}
