#include "main.h"

/**
 * print_triangle - Prints a triangle, followed by a new line (right aligned).
 * @size: The size of the triangle.
 *
 * Return: void.
 */
void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 1; i <= size; i++)
		{
			/* 1. Imprimer les espaces pour l'alignement à droite */
			for (j = 0; j < size - i; j++)
			{
				_putchar(' ');
			}

			/* 2. Imprimer les '#' */
			for (k = 0; k < i; k++)
			{
				_putchar('#');
			}

			/* 3. Saut de ligne */
			_putchar('\n');
		}
	}
}
