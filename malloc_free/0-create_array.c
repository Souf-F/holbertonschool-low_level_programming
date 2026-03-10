#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * create_array - crée un tableau de char et l'initialise
 * @size: la taille du tableau à créer
 * @c: le caractère d'initialisation
 *
 * Return: pointeur vers le tableau, ou NULL si ça échoue ou si size est 0
 */
char *create_array(unsigned int size, char c)
{
	char *str;
	unsigned int i;

	if (size == 0)
		return (NULL);

	str = malloc(sizeof(int) * size);

	if (str == 0)
		return (NULL);

	i = 0;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

