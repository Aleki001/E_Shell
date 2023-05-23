#include "main.h"
/**
 *get_tokens - string to be used during tokenization
 *@input:  string to be split
 *@bytes_read: no of bytes read using getline()
 *@arguments: string to be split to tokens
 *Return: tokens
 */
char **get_tokens(char *input, ssize_t bytes_read, char **arguments)
{
	char *token;
	char *input_dup = NULL;
	const char *delimeter = " \n";
	int i = 0, count_token = 0;

	input_dup = malloc(sizeof(char) * bytes_read);
	if (input_dup == NULL)
		exit(EXIT_FAILURE);
	_strcpy(input_dup, input);

	/*get no of tokens*/
	token = strtok(input_dup, delimeter);
	for (; token != NULL;)
	{
		count_token++;
		token = strtok(NULL, delimeter);
	}

	/* allocate space for all tokens*/
	arguments = malloc(sizeof(char *) * (count_token + 1));
	if (arguments == NULL)
		exit(EXIT_FAILURE);

	/*store evry token in argv array*/
	token = strtok(input, delimeter);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		arguments[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (arguments[i] == NULL)
			exit(EXIT_FAILURE);
		_strcpy(arguments[i], token);
		token = strtok(NULL, delimeter);
		i++;
	}
	arguments[i] = NULL;
	free(input_dup);
	return (arguments);
}
