#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int number;
	char letter;

	number = 0;
	while (number <= 9)
	{
		putchar(number + '0');
		number++;
	}

	letter = 'a';
	while (letter <= 'f')
	{
		putchar(letter);
		letter++;
	}

	putchar('\n');

	return (0);
}
