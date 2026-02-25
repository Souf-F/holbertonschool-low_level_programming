#include "main.h"
/**
 * print_most_numbers - affiche les chiffres de 0 à 9
 * sauf 2 et 4 suivis d'une nouvelle ligne
 *
 * Return: void (pas de valeur de retour)
 */
void print_most_numbers(void)
{
	int i = 0;

	while (i < 10)
	{
		if (i != 2 && i != 4)
		{
			_putchar(i + '0');
		}
		i++;
	}
	_putchar('\n');
}

