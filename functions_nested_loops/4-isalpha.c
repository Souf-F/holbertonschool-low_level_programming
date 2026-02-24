#include "main.h"
/**
 * _isalpha - main function
 *
 * @c: integer
 * Return: 1
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c <= 'A' && c >= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}

}
