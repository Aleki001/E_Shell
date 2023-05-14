#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>


char **get_tokens(char *input);
void execute_commands(char **argv);
void create_childProcess(char **arguments);









#endif
