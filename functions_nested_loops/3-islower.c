#include "main.h"

/**
 * _islower - vérifie si un caractère est en minuscule
 * @c: le caractère à vérifier (représenté par sa valeur ASCII)
 *
 * Return: 1 si c'est une minuscule, 0 sinon
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
