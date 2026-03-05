#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: The integer representation of the string.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	unsigned int result = 0;
	int found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (found == 1)
		{
			break;
		}
		i++;
	}

	return (result * sign);
}
