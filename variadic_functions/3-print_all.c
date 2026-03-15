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
			if (i == 0)
				printf("%c", va_arg(args, int));
			if (i == 1)
				printf("%d", va_arg(args, int));
			if (i == 2)
				printf("%f", va_arg(args, double));
			if (i == 3)
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
