#include "shell.h"

/**
* main - entry point
* @ac: arg count
* @argv: arg vector
* Return: 0 on success, 1 on error
*/

int main(int ac, char **argv)
{
	char *line = NULL, **command = NULL;
	int status = 0, index = 0;
	(void) ac;

	while (1)
	{
		line = read_line();

		if (line == NULL) /* ctrl + d handling end of file*/
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
		return (status);
		}
		index++;

		command = tokenize(line);

		if (!command)
		{
			continue;
		}

		if (is_builtin(command[0]))
		{
			handle_builtin(command, argv, &status, index);
		}
		else
		{
			status = _execute(command, argv, index);
		}
	}
}

