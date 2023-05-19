#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>


void execute_commands(char **arguments); /* executes command passed to it */
void create_childProcess(char **arguments); /* ensures after execution of command the loop continues to infinity */
char **get_tokens(char *input, ssize_t bytes_read, char **arguments); /* splits the string into arguments */
char *handle_path(char *command); /* gets location of a particular command */

/* Exits shell */
void builtin_exit(char **arr); 
int _atoi(char *s);
void freed(char **arr);


#endif
