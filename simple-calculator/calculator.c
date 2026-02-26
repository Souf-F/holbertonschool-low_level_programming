#include <stdio.h>
#include <stdlib.h>

/* Prototypes des fonctions */
void display_menu(void);
void addition(void);
void subtraction(void);
void multiplication(void);
void division(void);

/**
 * main - Point d'entrée du programme.
 *
 * Return: Toujours 0 (Succès).
 */
int main(void)
{
	int choice = -1;

	printf("Welcome to the Simple Calculator!\n");

	do {
		display_menu();

		/* Protection si scanf ne lit pas un entier */
		if (scanf("%d", &choice) != 1)
		{
			break;
		}

		switch (choice)
		{
		case 1:
			addition();
			break;
		case 2:
			subtraction();
			break;
		case 3:
			multiplication();
			break;
		case 4:
			division();
			break;
		case 0:
			printf("Bye!\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}
	} while (choice != 0);

	return (0);
}

/**
 * display_menu - Affiche le menu de la calculatrice.
 */
void display_menu(void)
{
	printf("\nSimple Calculator\n");
	printf("1) Add\n");
	printf("2) Subtract\n");
	printf("3) Multiply\n");
	printf("4) Divide\n");
	printf("0) Quit\n");
	printf("Choice: ");
}

/**
 * addition - Placeholder pour l'addition.
 */
void addition(void)
{
	printf("Addition selected\n");
}

/**
 * subtraction - Placeholder pour la soustraction.
 */
void subtraction(void)
{
	printf("Subtraction selected\n");
}

/**
 * multiplication - Placeholder pour la multiplication.
 */
void multiplication(void)
{
	printf("Multiplication selected\n");
}

/**
 * division - Placeholder pour la division.
 */
void division(void)
{
	printf("Division selected\n");
}
