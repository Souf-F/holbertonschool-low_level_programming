#include <stddef.h> /* Pour définir NULL */
#include "main.h"
/**
 * _strchr - localise un caractère dans une chaîne
 * @s: la chaîne de caractères à parcourir
 * @c: le caractère à rechercher
 *
 * Return: un pointeur vers la première occurrence de c, 
 * ou NULL si le caractère n'est pas trouvé.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}

		if (*s == '\0')
		{
			break;
		}

		s++;
	}

	return (NULL);
}