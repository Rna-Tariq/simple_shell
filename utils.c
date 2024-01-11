#include "shell.h"

/**
* free2Darr - a function that frees commands.
* @arr: command to be freed.
* Return: void
*/

void free2Darr(char **arr)
{
	int i;

	if (!arr)
	{
		return;
	}
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	free(arr), arr = NULL;
}

/**
* _itoa - converts an integer to a string
* @n: the number to be converted
* Return: 0 if no numbers in string, converted number otherwise
*/

char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}

	}

	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));

}

/**
* printerr - prints an error message
* @name: file name.
* @cmd: shell name.
* @index: number of errors.
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/

void printerr(char *name, char *cmd, int index)
{
	char *idx, *mssg = ": not found\n";

	idx = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, mssg, strlen(mssg));

	free(idx);
}


