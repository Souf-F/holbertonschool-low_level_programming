#include "main.h"
#include <stdio.h>
/**
 * _strspn - calcule la longueur d'un segment de préfixe
 * @s: la chaîne à scanner
 * @accept: la chaîne contenant les caractères autorisés
 *
 * Return: le nombre d'octets dans le segment initial de s
 * qui ne sont constitués que d'octets provenant de accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j;
	unsigned int count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				break; 
			}
		}

		if (accept[j] == '\0')
		{
			return (count);
		}

		count++;
	}

	return (count);
}
