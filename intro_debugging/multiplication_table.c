#include <stdio.h>
/**
 * print_table - Génère une table de multiplication
 * @size: L'entier définissant la limite supérieure de la table.
 *
 * après chaque série pour former la grille.
 */
void print_table(int size)
{
	int row, col;

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= size; col++)
		{
			printf("%d ", row * col);

		}
		printf("\n");
	}
}

/* -- DO NOT Modify the code below this line -- */
/**
 * main - Point d'entrée du programme.
 * * Return: Toujours 0 (Succès).
 */
int main(void)
{
	print_table(4);
	return (0);
}
