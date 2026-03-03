#include "main.h"

void print_rev(char *s)
{
	int longueur = 0;
	int rev;

	while (s[longueur] != '\0')
	{
		longueur++;
	}
	rev = longueur - 1;
	while (rev >= 0)
	{
		_putchar(s[rev]);
		rev--;
	}
	_putchar('\n');
}
