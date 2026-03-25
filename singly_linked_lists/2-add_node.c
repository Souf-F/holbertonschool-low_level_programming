#include "lists.h"

/**
 * add_node - Function
 * @head: linked list
 * @str: add this new element
 * Description: add element in a  linked list
 * Return: the new element
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *suit = malloc(sizeof(list_t));

	if (!suit)
	{
		free(suit);
		return (NULL);
	}

	if (!head)
		return (0);

	suit->str = strdup(str);
	suit->len = strlen(str);
	suit->next = *head;
	*head = suit;
	return (suit);
}
