#include "main.h"
#include <stdio.h>
/**
 * _strncat - Concatenates two strings using at most n bytes from src
 * @dest: The destination string to be appended to
 * @src: The source string to append
 * @n: The maximum number of bytes to use from src
 *
 * Return: A pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
		j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';

	return (dest);

}
