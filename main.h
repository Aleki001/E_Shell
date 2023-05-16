#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

char **get_tokens(char *input);/* generates tokens from user input by splitting the string */
void execute_commands(char **argv);/* function executes shell commands passed through */
void create_childProcess(char **arguments);/* ensures the prompt loop doesnot break */
char *handle_path(char *command);/* getts the location of command */








#endif
