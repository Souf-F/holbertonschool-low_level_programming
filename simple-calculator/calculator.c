#include <stdio.h>
#include <stdlib.h>

/**
 * main - Point d'entrée du programme.
 *
 * Return: Toujours 0 (Succès).
 */
int main(void)
{
    double a, b, resultat;
    int choixMenu;

    printf("Simple Calculator\n");
    printf("1 Add\n");
    printf("2 Soustraction\n");
    printf("3 Multiplication\n");
    printf("4 Division\n");
    printf("0 Quitter\n");

    if (scanf("%d", &choixMenu) != 1)
        return (1);

    if (choixMenu == 0)
    {
        printf("Bye !\n");
    }
    else if (choixMenu == 1)
    {
        printf("A:");
        scanf("%lf", &a);
        printf("B:");
        scanf("%lf", &b);
        resultat = a + b;
        printf("Resultat: %.0f\n", resultat);
    }
    else if (choixMenu == 2)
    {
        printf("A:");
        scanf("%lf", &a);
        printf("B:");
        scanf("%lf", &b);
        resultat = a - b;
        printf("Resultat: %.0f\n", resultat);
    }
    else if (choixMenu == 3)
    {
        printf("A:");
        scanf("%lf", &a);
        printf("B:");
        scanf("%lf", &b);
        resultat = a * b;
        printf("Resultat: %.0f\n", resultat);
    }
    else if (choixMenu == 4)
    {
        printf("A:");
        scanf("%lf", &a);
        printf("B:");
        scanf("%lf", &b);

        if (b == 0)
        {
            printf("Error: division by zero\n");
        }
        else
        {
            resultat = a / b;
            printf("Resultat: %f\n", resultat);
        }
    }
    else
    {
        printf("Invalid Choice\n");
    }

    return (0);
}

/**
 * Fonctions de calcul (Note: elles ne sont pas appelées dans votre main actuel)
 */

int Addition(int a, int b)
{
    return (a + b);
}

int Substract(int a, int b)
{
    return (a - b);
}

int Multiplication(int a, int b)
{
    return (a * b);
}

double Division(double a, double b)
{
    if (b == 0)
    {
        printf("Error: division by zero\n");
        return (0);
    }
    return (a / b);
}
