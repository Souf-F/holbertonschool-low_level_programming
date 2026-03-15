#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything based on a format string
 * @format: list of types of arguments passed to the function
 *          c: char, i: integer, f: float, s: char *
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *p;
	char *s;
	char *types;
	int first;
	int i;

	va_start(args, format);
	p = format;
	types = "cifs";
	first = 1;
	while (p && *p)
	{
		i = 0;
		s = NULL;
		while (types[i] && types[i] != *p)
			i++;
		if (types[i])
		{
			if (!first)
				printf(", ");
			first = 0;
			s = (i == 3) ? va_arg(args, char *) : NULL;
			printf(i == 0 ? "%c" : i == 1 ? "%d" : i == 2 ? "%f" : "%s",
				i == 0 ? va_arg(args, int) :
				i == 1 ? va_arg(args, int) :
				i == 2 ? (int)va_arg(args, double) :
				(int)(s ? s : "(nil)"));
		}
		p++;
	}
	printf("\n");
	va_end(args);
}