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