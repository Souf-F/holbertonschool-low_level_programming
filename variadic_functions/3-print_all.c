#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_char - prints a character
 * @list: list of arguments
 */

void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * print_int - prints an integer
 * @list: list of arguments
 */

void print_int(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_float - prints a float
 * @list: list of arguments
 */
void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * print_string - prints a string
 * @list: list of arguments
 */
void print_string(va_list list)
{
	char *str = va_arg(list, char*);

	if (str == NULL)
		str = "(nil)";

	printf("%s", str);
}

/**
 * print_all - prints anything
 * @format: a string of characters representing the types of arguments
 * @...: variable number of arguments to be printed
 */
void print_all(const char * const format, ...)
{
	int index1 = 0, index2;
	const char *separator = "";

	va_list list;

	checker storage[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(list, format);

	while (format && format[index1])
	{
		index2 = 0;

		while (storage[index2].type != NULL)
		{
			if (format[index1] == *storage[index2].type)
			{
				printf("%s", separator);
				storage[index2].function(list);
				separator = ", ";
				break;
			}
			index2++;
		}
		index1++;
	}

	printf("\n");
	va_end(list);
}
