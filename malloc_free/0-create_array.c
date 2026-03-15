#include "main.h"
#include <stdlib.h>
/**
 * create_array - Creates an array of chars and initializes it.
 * @size: The size of the array to create.
 * @c: The char to initialize the array with.
 *
 * Description: Allocates memory for an array of chars using malloc
 * and fills it with a specific character.
 *
 * Return: A pointer to the array, or NULL if size is 0 or if it fails.
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *tab;

	if (size == 0)
	{
		return (NULL);
	}

	tab = (char *) malloc(size * sizeof(char));

	if (tab == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		tab[i] = c;
		i++;
	}
	return (tab);
}
