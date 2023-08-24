#include "monty.h"

/**
 * _strcmp - Custum strcmp
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 or 1
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * is_delimiter - Check if a char is delimiter
 * @c: the character
 * @delim: string of delimiters
 *
 * Return: 0 or 1
 */
int is_delimiter(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - Custum strtok
 * @str: string
 * @delim: delimiter
 *
 * Return: One string at the time
 */
char *_strtok(char *str, char *delim)
{
	static char *token = NULL;
	static char *prev_str = NULL;

	if (str != NULL)
	{
		prev_str = str;
		token = NULL;
	}
	else if (prev_str != NULL)
		str = prev_str;
	else
		return (NULL);

	while (*str != '\0' && is_delimiter(*str, delim))
		str++;

	if (*str == '\0')
	{
		prev_str = NULL;
		return (NULL);
	}

	token = str;

	while (*str != '\0' && !is_delimiter(*str, delim))
		str++;

	if (*str != '\0')
	{
		*str = '\0';
		prev_str = str + 1;
	}
	else
		prev_str = NULL;

	return (token);

}

/**
 * _strlen - Custum strlen function
 * @str: string
 *
 * Return: Length of str
 */
size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}
