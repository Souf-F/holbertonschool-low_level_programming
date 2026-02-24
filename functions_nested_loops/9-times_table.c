#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int l, c, r;

	for (r = 0; r <= 9; r++)
	{
		for (c = 0; c <= 9; c++)
		{
			l = r * c;

			if (c == 0)
			{
				_putchar('0');
			}
			else
			{
				_putchar(',');
				_putchar(' ');

				if (l <= 9)
				{
					_putchar(' ');
					_putchar(l + '0');
				}
				else
				{
					_putchar((l / 10) + '0');
					_putchar((l % 10) + '0');
				}
			}
		}
		_putchar('\n');
	}
}
