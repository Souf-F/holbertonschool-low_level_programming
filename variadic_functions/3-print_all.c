#include "variadic_functions.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * print_int - prints an integer using _putchar
 * @n: the integer to print
 */
void print_int(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10)
		print_int(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * print_str - prints a string using _putchar
 * @s: the string to print
 */
void print_str(char *s)
{
	int i;

	i = 0;
	if (s == 0)
		s = "(nil)";
	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * print_all - prints anything based on a format string
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *p;
	char *s;
	int first;

	va_start(args, format);
	p = format;
	first = 1;
	while (p && *p)
	{
		s = NULL;
		if (*p == 'c' || *p == 'i' || *p == 'f' || *p == 's')
		{
			if (!first)
			{
				_putchar(',');
				_putchar(' ');
			}
			first = 0;
			if (*p == 'c')
				_putchar(va_arg(args, int));
			if (*p == 'i')
				print_int(va_arg(args, int));
			if (*p == 'f')
				print_int((int)va_arg(args, double));
			if (*p == 's')
			{
				s = va_arg(args, char *);
				print_str(s);
			}
		}
		p++;
	}
	_putchar('\n');
	va_end(args);
}
