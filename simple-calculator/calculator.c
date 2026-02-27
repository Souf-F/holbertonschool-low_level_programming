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

	printf("Simple Calculator\n");
	printf("1 Add\n");
	printf("2 Soustraction\n");
	printf("3 Multiplication\n");
	printf("4 Division\n");
	printf("0 Quitter\n");

	scanf("%d", &choixMenu);

	if  (choixMenu == 0)
	{
		printf("Bye !\n");

	}
	else if (choixMenu == 1)
{
	int a, b, resultat;

printf("A:");
	scanf("%d", &a);
printf("B:");
	scanf("%d", &b);
		resultat = a + b;

	printf("Resultat: %d\n", resultat);
}

else
	{
	printf("Invalid Choice\n");
	}
	return (0);

}
/**
 * Addition - Calcule la somme de deux entiers
 * @a: Le premier entier
 * @b: Le second entier
 *
 * Return: La somme de a et b
 */
int Addition(int a, int b)
{
	int resultat;

	printf("a");
	scanf("%d", &a);
	printf("b");
	scanf("%d", &b);

	resultat = a + b;
	printf("Resultat %d\n", resultat);

	return (resultat);
}
