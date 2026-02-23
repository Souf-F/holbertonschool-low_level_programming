#include <stdio.h>

/**
 * main - Point d'entrée
 *
 * Description : Affiche 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	int n;

	n = 0;
	while (n <= 9)
	{
		putchar(n + '0');

		if (n < 9)
		{
			putchar(',');
			putchar(' ');
		}
		n++;
	}
	putchar('\n');

	return (0);
}
