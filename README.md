0x16. C - Simple Shell

Authored by:

Ehidiamen Martha and Kinyua Alex

Compiler used for all .c files

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

Testing
Your shell should work like this in interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

Builtin Commands
cd
Changes the current directory of the process.
Command syntax: cd [DIRECTORY]
If no argument is given to cd the command must be interpreted like cd $HOME
You have to handle the command cd -
You have to update the environment variable PWD when you change directory

exit
Exits the shell.
The STATUS argument is the integer used to exit the shell.
If no argument is given, the command is interpreted as exit 0.

env
Prints the current environment.

setenv
Initialize a new environment variable, or modify an existing one
Command syntax: setenv VARIABLE VALUE
Should print something on stderr on failure

unsetenv
Remove an environment variable
Command syntax: unsetenv VARIABLE
Should print something on stderr on failure
