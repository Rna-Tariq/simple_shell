#include "shell.h"

/**
* _strcat - a function that concatenates two strings.
* @dest: first input.
* @src: second input.
* Return: a pointer to the resulting string dest.
*/

char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
* reverse_string - a function that reverses a string.
* @str: string to be reversed.
* @len: string length.
* Return: void.
*/
void reverse_string(char *str, int len)
{
	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
