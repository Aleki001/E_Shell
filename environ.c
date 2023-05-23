#include "main.h"

/**
 * env - prints the current environment
 * @arr: array
 */

void env(char **arr __attribute__ ((unused)))
{
	int a;

	for (a = 0; environ[a]; a++)
	{
		_puts(environ[a]);
		_puts("\n");
	}
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @arr: Array
 */

void _setenv(char **arr)
{
	int i;
	int j;
	int k;

	if (!arr[1] || !arr[2])
	{
		perror(_gets("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arr[1][j] == environ[i][j])
		{
			while (arr[1][j])
			{
				if (arr[1][j] != environ[i][j])
					break;
				j++;
			}
			if (arr[1][j] == '\0')
			{
				k = 0;
				while (arr[2][k])
				{
					environ[i][j + 1 + k] = arr[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = _concats(arr[1], "=", arr[2]);
		environ[i + 1] = '\0';
	}

}

/**
 * _unsetenv - Remove an environment variable
 * @arr: array
 */

void _unsetenv(char **arr)
{
	int i;
	int j;

	if (!arr[1])
	{
		perror(_gets("_"));
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arr[1][j] == environ[i][j])
		{
			while (arr[1][j])
			{
				if (arr[1][j] != environ[i][j])
					break;

				j++;
			}
			if (arr[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
