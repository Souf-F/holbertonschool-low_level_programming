#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything based on a format string
 * @format: list of types of arguments passed to the function
 *
 * Return: void
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
		if (*p == 'c' || *p == 'i' || *p == 'f' || *p == 's')
		{
			if (!first)
				printf(", ");
			first = 0;
			if (*p == 'c')
				printf("%c", va_arg(args, int));
			if (*p == 'i')
				printf("%d", va_arg(args, int));
			if (*p == 'f')
				printf("%f", va_arg(args, double));
			if (*p == 's')
			{
				s = va_arg(args, char *);
				printf("%s", s ? s : "(nil)");
			}
		}
		p++;
	}
	printf("\n");
	va_end(args);
}
