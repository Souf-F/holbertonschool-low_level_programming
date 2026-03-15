#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - main function
 * @argc: argument count
 * @argv: argument value
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int a, b;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	operation = get_op_func(argv[2]);

	if (operation == NULL)
	{
		printf("Error\n");
		return (99);
	}

	if ((strcmp(argv[2], "/") == 0 || strcmp(argv[2], "%") == 0) && b == 0)
	{
		printf("Error\n");
		return (100);
	}

	printf("%d\n", operation(a, b));

	return (0);
}

