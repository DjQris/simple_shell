#include "shell.h"

/**
 * _strlen - Compute length of string
 * @s: pointer to char type (string)
 *
 * Return: Length of string `int`
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*(s++) != '\0')
		len++;

	return (len);
}
