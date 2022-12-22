#include "shell.h"

/**
 * _strcmp - compare strings
 * @s1: string
 * @s2: string
 *
 * Return: Difference between the first unmatched character
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

/**
  * _strncmp - Compares at most the first n bytes of str1 and str2
  * @s1: The first string
  * @s2: The second string
  * @len: The limit bytes of comparison
  *
  * Return: int value
  */
int _strncmp(const char *s1, const char *s2, size_t len)
{
	unsigned int pos = 0;
	int diff = 0;

	while (pos < len)
	{
		if (s1[pos] == s2[pos])
		{
			pos++;
			continue;
		}
		else
		{
			diff = s1[pos] - s2[pos];
			break;
		}

		pos++;
	}

	return (diff);
}
