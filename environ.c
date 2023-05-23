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

