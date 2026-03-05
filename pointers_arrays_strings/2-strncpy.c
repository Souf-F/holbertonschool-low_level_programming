#include "main.h"
#include <stdlib.h>
/**
 * @src: The source string to be copied.
 * @n: The maximum number of characters to copy from src.
 * Return: A pointer to the destination string (dest).
 * If src is n characters or more, dest will not be null-terminated.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
