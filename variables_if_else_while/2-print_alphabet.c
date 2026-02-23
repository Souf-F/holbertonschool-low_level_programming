#include <stdio.h>

/**
 * main - Affiche l'alphabet en minuscules
 * Return: Always 0
 */
int main(void)
{
char lettre = 'a';

while (lettre <= 'z')
{
putchar(lettre);
lettre++;
}
putchar('\n');

return (0);
}
