#include "dog.h"
#include <stdlib.h>
/**
 * new_dog - Creates a new dog.
 * @name: Name of the dog.
 * @age: Age of the dog.
 * @owner: Owner of the dog.
 *
 * Return: Pointer to the new dog (dog_t), or NULL if it fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int i;
	char *name_copy;
	char *owner_copy;

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);
	for (i = 0; name[i] != '\0'; i++)
		;
	name_copy = malloc(i + 1);
	if (name_copy == NULL)
	{
		free(d);
		return (NULL);
	}
	for (i = 0; owner[i] != '\0'; i++)
		;
	owner_copy = malloc(i + 1);
	if (owner_copy == NULL)
	{
		free(d);
		free(name_copy);
		return (NULL);
	}
	for (i = 0; name[i] != '\0'; i++)
		name_copy[i] = name[i];
	name_copy[i] = '\0';
	for (i = 0; owner[i] != '\0'; i++)
		owner_copy[i] = owner[i];
	owner_copy[i] = '\0';
	d->name = name_copy;
	d->age = age;
	d->owner = owner_copy;
	return (d);
}
