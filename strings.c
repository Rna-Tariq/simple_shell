#include "shell.h"

/**
* _strdup - a function that duplicates string.
* @str: string to be duplicated.
* Return: a pointer to duplicated string.
*/

char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}

/**
* _strcmp - a function that compares 2 strings.
* @s1: 1st string
* @s2: 2nd string
* Return: differneces between 2 strings.
*/

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*s1)
	{
		if (*s1 != *s2)
		{
			i = ((int)*s1 - 48) - ((int)*s2 - 48);
			break;
		}
		s1++;
		s2++;
	}
	return (i);
}

/**
* _strcpy - copies the string pointed to by src,
* including the terminating null byte, to the
* buffer pointed to by dest.
* @dest: destination.
* @src: source.
* Return: the pointer to dest.
*/

char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		*(dest + count) = *(src + count);
		if (*(src + count) == '\0')
			break;
		count++;
	}
	return (dest);
}

/**
* _strlen - returns the length of a string
* @s: the string length to check
* Return: integer length of string
*/

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}
