#include "shell.h"

/**
* is_positive_number - a function checks if
* the number is positive.
* @str: input.
* Return: 0.
*/

int is_positive_number(char *str)
{
	int i;

	if (!str)
	{
		return (0);
	}
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
*_atoi - converts a string to an integer
*@str: the string to be converted
*Return: 0 if no numbers in string, converted number otherwise
*/

int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num += (str[i] - '0');
	}
	return (num);
}
