#include "shell.h"

/**
* _execute - a function that executes commands.
* @command: command to be executed.
* @argv: arg vector.
* @index: index of errors.
* Return: execution status.
*/

int _execute(char **command, char **argv, int index)
{
	char *full_cmd;
	pid_t child;
	int status;

	full_cmd = _getPath(command[0]);

	if (!full_cmd)
	{
		printerr(argv[0], command[0], index);
		free2Darr(command);
		return (127);
	}
	child = fork();
	if (child == 0)
	{
		if (execve(full_cmd, command, environ) == -1)
		{
			free(full_cmd), full_cmd = NULL;
			free2Darr(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free2Darr(command);
		free(full_cmd), full_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}

