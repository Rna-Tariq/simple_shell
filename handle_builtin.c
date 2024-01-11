#include "shell.h"

/**
* is_builtin - a function that checks for the builtins.
* @command: input.
* Return: 0
*/

int is_builtin(char *command)
{
	char *builtins[] = {
		"exit",
		"env",
		"setenv",
		"cd",
		NULL
	};

	int i;

	for (i = 0; builtins[i]; i++)
	{
		if (_strcmp(command, builtins[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
* handle_builtin - a function that handles the builtins.
* @command: input.
* @argv: arg vector.
* @status: cmd status.
* @index: index of errors.
* Return: void.
*/

void handle_builtin(char **command, char **argv, int *status, int index)
{
	(void) argv;
	(void) index;

	if (_strcmp(command[0], "exit") == 0)
	{
		exit_shell(command, argv, status, index);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		print_env(command, status);
	}
}

/**
* exit_shell - exits the shell.
* @command: input.
* @argv: arg vector.
* @status: cmd status.
* @index: index of errors.
* Return: void.
*/

void exit_shell(char **command, char **argv, int *status, int index)
{
	int exit_value = (*status);
	char *idx, mssg[] = ": exit: Illegal number: ";

	if (command[1])
	{
		if (is_positive_number(command[1]))
		{
			exit_value = _atoi(command[1]);
		}
		else
		{
			idx = _itoa(index);

			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, _strlen(idx));
			write(STDERR_FILENO, mssg, _strlen(mssg));
			write(STDERR_FILENO, command[1], _strlen(command[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			free2Darr(command);
			(*status) = 2;
			return;
		}
	}
	free2Darr(command);
	exit(exit_value);
}

/**
* print_env - a function that prints the environment.
* @command: input.
* @status: cmd status.
* Return: void.
*/

void print_env(char **command, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free2Darr(command);
	*status = 0;
}
