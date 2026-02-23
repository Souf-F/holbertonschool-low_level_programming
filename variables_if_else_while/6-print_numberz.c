#include <stdio.h>

/**
 * main - Point d'entrée
 *
 * Description : Affiche tous les chiffres de la base 10 (0-9)
 * suivi d'un saut de ligne.
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	int digit;

	digit = 0;
	while (digit <= 9)
	{
		putchar(digit + '0');
		digit++;
		putchar('\n');
	}

	return (0);
}
