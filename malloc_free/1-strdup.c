#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _strdup - Renvoie un pointeur vers un nouvel espace mémoire contenant
 * une copie de la chaîne donnée en paramètre.
 * @str: La chaîne de caractères à copier.
 *
 * Return: Un pointeur vers la chaîne dupliquée,
 * ou NULL si str est NULL ou si l'allocation échoue.
 **/
char *_strdup(char *str)
{
	char *copy;
	unsigned int i, len;

	if (str == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (str[len] != '\0')
	len++;

	copy = malloc((len + 1) * sizeof(char));

	if (copy == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (i <= len)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

