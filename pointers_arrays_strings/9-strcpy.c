#include "main.h"

/**
 * _strcpy - Copies a string.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
char *ptr = dest;

while (*src != '\0')
{
*ptr = *src;
ptr++;
src++;
}
*ptr = '\0';

return (dest);
}
