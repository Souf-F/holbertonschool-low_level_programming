#include "variadic_functions.h"
#include <stdarg.h>
/**
 * sum_them_all - Calcule la somme de tous ses paramètres.
 * @n: Le nombre d'arguments passés à la fonction.
 *
 * Return: La somme totale. Si n == 0, retourne 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	int sum = 0;

	if (n == 0)
		return (0);

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(ap, int);
	}

	va_end(ap);

	return (sum);
}
