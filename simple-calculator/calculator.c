#include <stdio.h>
#include <stdlib.h>
/**
 * main - Point d'entrée du programme.
 *
 * Return: Toujours 0 (Succès).
 */
int main(void)
{
	int choixMenu;

	printf("Simple Calculator");
	printf("1 Add\n");
	printf("2 Soustraction\n");
	printf("3 Multiplication\n");
	printf("4 Division\n");
	printf("0 Quitter\n");

	scanf("%d", &choixMenu);

	if (choixMenu == 0)
	{
		printf("Bye !\n");

	} else
	{
	printf("Invalid Choice\n");
	}

	return (0);
}
