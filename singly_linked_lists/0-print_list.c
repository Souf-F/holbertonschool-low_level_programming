#include "lists.h"
#include <stddef.h>
#include <stdio.h>
/**
 * print_list - Affiche tous les éléments d'une liste list_t.
 * @h: Pointeur vers le début de la liste (head).
 *
 * Return: Le nombre de nœuds dans la liste.
 */
size_t print_list(const list_t *h)
{
	int compteur = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
		{
			printf("[%d] %s\n", h->len, h->str);
		}
		compteur++;
		h = h->next;
	}
	return (compteur);
}
