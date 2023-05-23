#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

/* basic custom library function prototypes */
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strcat(char *dest, char *src);


/* main process prototypes */
void execute_commands(char **arguments);
void create_childProcess(char **arguments);
char **get_tokens(char *input, ssize_t bytes_read, char **arguments);
char *handle_path(char *command);


/* Exits shell */
void builtin_exit(char **arr);
int _atoi(char *s);
void freed(char **arr);

/* Environment */
void env(char **arr __attribute__ ((unused)));

/* Environment help */
int _putchar(char c);
void _puts(char *str);


#endif
