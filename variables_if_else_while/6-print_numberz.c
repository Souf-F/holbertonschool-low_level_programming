#include <stdio.h>

/**
 * main - Point d'entrée du programme
 *
 * Description : Affiche les chiffres de 0 à 9 sur une seule ligne
 * sans utiliser de variable de type char.
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	int n;

	n = 0;
	while (n <= 9)
	{
		putchar(n + '0');
		n++;
	}
	putchar('\n');

	return (0);
}