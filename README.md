# Simple Shell

This is a simple shell program that allows you to execute both executables and built-in commands. It provides a basic command-line interface where you can enter commands and receive corresponding output.

## Features

The shell supports the following features:

- Execution of external executables: You can run any executable file by typing its name and providing any necessary arguments.
- Built-in commands: The shell provides a set of built-in commands that can be executed directly within the shell.
- Environment variables: The shell supports environment variables and allows you to set, get, and modify them.

## Limitations

The current implementation of the shell has the following limitations:

- Redirecting: The shell does not support advanced input/output redirection techniques like `>` (output redirection to a file) or `|` (piping output to another command).
- Shell piping: The shell does not support piping the output of one command as input to another command.
- Aliases: The shell does not provide a built-in mechanism for defining and using command aliases.

## Getting Started

To use the shell, follow these steps:

1. Clone the repository: `git clone https://github.com/your-repository.git`
2. Compile the source code: `gcc shell.c -o shell`
3. Run the shell: `./shell`

## Usage

Once you have the shell running, you can enter commands and press Enter to execute them. Here are some examples of how to use the shell:

- Run an executable: `./my_executable arg1 arg2`
- Execute a built-in command: `cd /path/to/directory`
- Set an environment variable: `set VAR_NAME=variable_value`
- Get the value of an environment variable: `echo $VAR_NAME`
- Run a shell script: `./my_script.sh`


## Authors

- Alex Kinyua
- Martha Ehidiamen
