#include "main.h"

/**
 * print_last_digit - Affiche et renvoie le dernier chiffre d'un nombre.
 * @n: Le nombre à traiter.
 *
 * Return: La valeur du dernier chiffre.
 */
int print_last_digit(int n)
{
	int last;

	last = n % 10;

	if (last < 0)
	{
		last = last * -1;
	}

	_putchar(last + '0');

	return (last);
}
