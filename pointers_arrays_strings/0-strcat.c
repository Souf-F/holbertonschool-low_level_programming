#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Pointer to the destination string
 * @src: Pointer to the source string
 *
 * Return: Pointer to the destination memory area (dest)
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
	{
		ptr++;
	}

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}
