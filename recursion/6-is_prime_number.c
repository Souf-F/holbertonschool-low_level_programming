#include "main.h"

/**
 * is_prime_helper - recursive helper to check divisibility
 * @n: the number to check
 * @divisor: current divisor being tested
 *
 * Return: 1 if no divisor found (prime), 0 if divisible
 */
int is_prime_helper(int n, int divisor)
{
	if (divisor * divisor > n)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (is_prime_helper(n, divisor + 1));
}

/**
 * is_prime_number - returns 1 if n is prime, 0 otherwise
 * @n: the integer to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (is_prime_helper(n, 2));
}
