// #include "shell.h"
// /**
//  *get_tokens - string to be used during tokenization
//  *@input:  string to be split
//  *@bytes_read: no of bytes read using getline()
//  *@arguments: string to be split to tokens
//  *Return: tokens
//  */
// char **get_tokens(char *input, ssize_t bytes_read, char **arguments)
// {
// 	char *token;
// 	char *input_dup = NULL;
// 	char *delim = " \n";
// 	int i = 0, count_token = 0;

// 	input_dup = malloc(sizeof(char) * bytes_read);
// 	if (input_dup == NULL)
// 		exit(EXIT_FAILURE);
// 	_strcpy(input_dup, input);

// 	/*get no of tokens*/
// 	token = strtok(input_dup, delim);
// 	for (; token != NULL;)
// 	{
// 		count_token++;
// 		token = strtok(NULL, delim);
// 	}

// 	/* allocate space for all tokens*/
// 	arguments = malloc(sizeof(char *) * (count_token + 1));
// 	if (arguments == NULL)
// 		exit(EXIT_FAILURE);

// 	/*store evry token in argv array*/
// 	token = strtok(input, delim);
// 	while (token != NULL)
// 	{
// 		if (token[0] == '#')
// 			break;
// 		arguments[i] = malloc(sizeof(char) * (_strlen(token) + 1));
// 		if (arguments[i] == NULL)
// 			exit(EXIT_FAILURE);
// 		_strcpy(arguments[i], token);
// 		token = strtok(NULL, delim);
// 		i++;
// 	}
// 	arguments[i] = NULL;
// 	free(input_dup);
// 	return (arguments);
// }

#include "shell.h"

/**
 * get_tokens - string to be used during tokenization
 * @input:  string to be split
 * @bytes_read: no of bytes read using getline()
 * @arguments: string to be split to tokens
 * Return: tokens
 */
char **get_tokens(char *input, ssize_t bytes_read, char **arguments)
{
	char *token;
	char *input_dup = NULL;
	char *delim = " \n";
	int i = 0, count_token = 0;

	// Check if the input is empty or null
	if (input == NULL || bytes_read <= 0) {
		arguments = malloc(sizeof(char *));
		if (arguments == NULL)
			exit(EXIT_FAILURE);
		arguments[0] = NULL;
		return arguments;
	}

	input_dup = malloc(sizeof(char) * bytes_read);
	if (input_dup == NULL)
		exit(EXIT_FAILURE);

	_strcpy(input_dup, input);

	/* get no of tokens */
	token = strtok(input_dup, delim);
	for (; token != NULL;) {
		count_token++;
		token = strtok(NULL, delim);
	}

	/* allocate space for all tokens */
	arguments = malloc(sizeof(char *) * (count_token + 1));
	if (arguments == NULL) {
		free(input_dup); // Release input_dup before exiting
		exit(EXIT_FAILURE);
	}

	/* store every token in argv array */
	token = strtok(input, delim);
	while (token != NULL) {
		if (token[0] == '#')
			break;
		arguments[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (arguments[i] == NULL) {
			// Free already allocated memory before exiting
			while (i > 0) {
				free(arguments[--i]);
			}
			free(arguments);
			free(input_dup);
			exit(EXIT_FAILURE);
		}
		_strcpy(arguments[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	arguments[i] = NULL;
	free(input_dup); // Release input_dup after its use
	return (arguments);
}

