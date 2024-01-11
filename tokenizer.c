#include "shell.h"

/**
* tokenize - a function that splits commands.
*
* @line: command to be splitted.
*
* Return: splitted command.
*/

char **tokenize(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cp = 0, i = 0;

	if (!line)
	{
		return (NULL);
	}

	tmp  = _strdup(line);
	token = strtok(tmp, DELIM);

	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while (token)
	{
		cp++;
		token = strtok(NULL, DELIM);
	}
	free(tmp);

	command = malloc(sizeof(char *) * (cp + 1));

	if (!command)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, DELIM);

	while (token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL, command[i] = NULL;
	return (command);

}

