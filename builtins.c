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
		status = _atoi(arguments[1]);
		exit(status);
	}
	else
	{
		exit(0);
	}
}

/**
 * env_builtin - displays the environment
 * @arguments: commands
 * Return: 1 otherwise 0
 */
int env_builtin(char **arguments)
{
	int i;

	(void)arguments;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}

	return (-1);
}

/**
 * help_builtin - displays help
 * @arguments: commands
 * Return: 1 otherwise 0
 */
int help_builtin(char **arguments)
{
	char *info = "\n\n\t\t\tWelcome to the help page.\n";

	(void)arguments;

	write(STDOUT_FILENO, info, _strlen(info));
	info = "\nThe following are the builtin commands in this shell.\n";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\n\t\t cd \t env \t help \t exit \n";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\n\t1. To navigate throught the directories  use the 'cd' command.\n";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\t2. TO exit shell use the 'exit' command.\n";
	write(STDOUT_FILENO, info, _strlen(info));
	info = "\t3. For help type 'help' command.\n\n";
	write(STDOUT_FILENO, info, _strlen(info));

	return (1);
}

/**
 * cd_builtin - changes directory when invoked
 * @arguments: commands
 * Return: 1 otherwise 0
 */
int cd_builtin(char **arguments)
{
	(void)arguments;
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
		{"env", env_builtin},
		{"help", help_builtin}
	};

	if (arguments[0] == NULL)
		return (1);
	while (i < 4)
	{
		if (_strcmp(arguments[0], builtins[i].name) == 0)
			return (builtins[i].function(arguments));
		i++;
	}

	return (launch(arguments));
}
