#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

/* basic custom library function prototypes */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);


/* handling path and tokenization prototypes */
char **get_tokens(char *input, ssize_t bytes_read, char **arguments);
char *handle_path(char *command);



/**
 *struct builtins - builtin commands
 *@name: name of builtin command
 *@function: points  to the function associated to each builtin command
 */
typedef struct builtins
{
	const char *name;
	int (*function)(char **arguments);
} builtin_command;

/* Function prototypes for builtin commands */
int exit_builtin(char **arguments);
int cd_builtin(char **arguments);
int help_builtin(char **arguments);
int execute_commands(char **arguments);
int launch(char **arguments);


#endif
