#include "main.h"
#include "stdio.h"

/**
 * _atoi -  convert a string to an integer
 * @s: String
 * Return: int value
 */

int _atoi(char *s)
{
	int str = 1;
	unsigned int val = 0;

	do {
		if (*s == '-')
			str *= -1;
		else if (*s >= '0' && *s <= '9')
			val = (val * 10) + (*s - '0');
		else if (val > 0)
			break;
	} while (*s++);

	return (val * str);
}

/**
 * freed - frees the array
 * @arr: array
 */

void freed(char **arr)
{
	int a;

	for (a = 0; arr[a]; a++)
		free(arr[a]);
	free(arr);
}

/**
 * builtin_exit - Exits the shell
 * @arr: array
 * Return: Always 0 (Success)
 */

void builtin_exit(char **arr)
{
	int i, j;

	if (arr[1])
	{
		j = _atoi(arr[1]);
		if (j <= -1)
			j = 2;
		freed(arr);
		exit(j);
	}
	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
	exit(0);
}
