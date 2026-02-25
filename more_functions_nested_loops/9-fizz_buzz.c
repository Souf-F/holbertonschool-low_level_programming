#include <stdio.h>
#include "main.h"
/**
 * main - point d'entrée du programme
 *
 * Description: imprime les nombres de 1 à 100.
 * Pour les multiples de 3, imprime Fizz.
 * Pour les multiples de 5, imprime Buzz.
 * Pour les multiples de 3 et 5, imprime FizzBuzz.
 *
 * Return: toujours 0 (succès)
 */
int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
		{
			printf("FizzBuzz");
			}
			else if (i % 3 == 0)
			{
			printf("Fizz");
			}
			else if (i % 5 == 0)
			{
			printf("Buzz");
			}
			else
			{
			printf("%d", i);
			}
		if (i < 100)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}
