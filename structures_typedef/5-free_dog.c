#include "dog.h"
#include <stdlib.h>
/**
 * free_dog - Frees memory allocated for a struct dog.
 * @d: struct dog to free.
 *
 * Description: Frees the strings name and owner,
 * then frees the dog structure itself.
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;
	free(d->owner);
	free(d->name);
	free(d);
}
