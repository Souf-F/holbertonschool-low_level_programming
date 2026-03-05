#include <stddef.h> /* Pour définir NULL */
#include "main.h"
/** * _strstr - localise une sous-chaîne dans une chaîne
 * @haystack: la chaîne de caractères à parcourir
 * @needle: la sous-chaîne à rechercher
 *
 * Return: un pointeur vers la première occurrence de needle dans haystack,
 * ou NULL si needle n'est pas trouvé.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '0')
	{
		char *h = haystack;
		char *n = needle;

		while (*h == *n && *n != '\0')
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (NULL);
}
