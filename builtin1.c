#include "main.h"

/**
* _builtin - checks commands
* @arr: array of arguments
* Return: pointer to function
*/

void(*_builtin(char **arr))(char **arr)
{

	mybuiltin A[] = {
		{"env", env},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};
	int i;
	int j;

	for (i = 0; A[i].arguments; i++)
	{
		j = 0;
		if (A[i].arguments[j] == arr[0][j])
		{
			for (j = 0; arr[0][j]; j++)
			{
				if (A[i].arguments[j] != arr[0][j])
					break;
			}
			if (!arr[0][j])
				return (A[i].functions);
		}
	}
	return (0);
}
