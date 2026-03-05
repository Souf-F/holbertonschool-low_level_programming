#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string to be scanned.
 * @accept: The string containing the characters to match.
 *
 * Return: A pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *t = accept;

		while (*t != '\0')
		{
			if (*s == *t)
			{
				return (s);
			}
			t++;
		}
		s++;
	}

	return (NULL);
}
