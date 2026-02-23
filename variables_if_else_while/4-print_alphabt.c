#include <stdio.h>

/**
 * main - Point d'entrée du programme
 *
 * Description: Affiche l'alphabet en minuscules sauf 'q' et 'e',
 * suivi d'une nouvelle ligne.
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	char letter;

	letter = 'a';
	while (letter <= 'z')
	{
		if (letter != 'e' && letter != 'q')
		{
			putchar(letter);
		}
		letter++;
	}
	putchar('\n');

	return (0);
}
