#include <stdio.h>
#include <stdarg.h>

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
		if (!first && (*p == 'c' || *p == 'i' || *p == 'f' || *p == 's'))
			printf(", ");
		first = 0;
		p++;
	}
	printf("\n");
	va_end(args);
}
