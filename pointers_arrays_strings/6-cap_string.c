#include "main.h"
/**
 * grand_separateur - Checks if a character is a word separator.
 * @c: The character to check.
 *
 * Return: 1 if it is a separator, 0 otherwise.
 */
int grand_separateur(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == ','
		|| c == ';' || c == '.' || c == '!' || c == '?'
		|| c == '"' || c == '(' || c == ')' || c == '{'
		|| c == '}')
		return (1);
	return (0);
}
/**
 * cap_string - Capitalizes all words of a string.
 * @s: The string to be modified.
 *
 * Description: Capitalizes the first letter of every word based on
 * specific separators and ensures other letters are lowercase.
 *
 * Return: Pointer to the modified string s.
 */
char *cap_string(char *s)
{
	int i = 0;
	int separateur = 1;

	while (s[i] != '\0')
	{
		if (grand_separateur(s[i]))
		{
			separateur = 1;
		}
		else if (s[i] >= 'a' && s[i] <= 'z' && separateur == 1)
		{
			s[i] -= 32;
			separateur = 0;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z' && separateur == 0)
		{
			s[i] += 32;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z' && separateur == 1)
		{
			separateur = 0;
		}
		else
		{
			separateur = 0;
		}
		i++;
	}
	return (s);
}
