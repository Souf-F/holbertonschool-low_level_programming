#include "main.h"

/**
 * print_alphabet - imprime l'alphabet en minuscules
 *
 * Return: void (ne renvoie rien)
 */
void print_alphabet(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}
