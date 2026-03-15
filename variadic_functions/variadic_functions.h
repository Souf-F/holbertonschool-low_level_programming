#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * struct formats - Struct to map format types to functions
 * @type: The format type as a string
 * @function: The function pointer to handle that type
 */

typedef struct formats
{
	char *type;
	void (*function)(va_list);
} checker;

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
