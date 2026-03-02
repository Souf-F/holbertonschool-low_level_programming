#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 50000

/**
 * data - Tableau statique pour stocker les entiers
 *
 * Description: Ce tableau est utilisé pour comparer les algorithmes
 * de comptage de nombres pairs.
 */
static int data[ARRAY_SIZE];

/**
 * initialize_data - Remplit le tableau avec des entiers consécutifs.
 *
 * Return: void.
 */
static void initialize_data(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE; i++)
		data[i] = i;
}

/**
 * count_even_naive - Compte les nombres pairs de manière naïve (O(n^2)).
 *
 * Return: Le nombre total de nombres pairs trouvés.
 */
static int count_even_naive(void)
{
	int count;
	int i;
	int j;

	count = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (data[j] % 2 == 0)
				count++;
		}
	}

	return (count);
}

/**
 * count_even_single_pass - Compte les nombres pairs en un seul passage (O(n)).
 *
 * Return: Le nombre total de nombres pairs trouvés.
 */
static int count_even_single_pass(void)
{
	int count;
	int i;

	count = 0;

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		if (data[i] % 2 == 0)
			count++;
	}

	return (count);
}

/**
 * main - Point d'entrée pour comparer deux algorithmes de comptage.
 *
 * Return: Toujours 0 (Succès).
 */
int main(void)
{
	clock_t start;
	clock_t end;
	double elapsed_a;
	double elapsed_b;
	int result_a;
	int result_b;

	initialize_data();

	/* Mesure de l'algorithme naïf */
	start = clock();
	result_a = count_even_naive();
	end = clock();
	elapsed_a = (double)(end - start) / (double)CLOCKS_PER_SEC;

	/* Mesure de l'algorithme optimisé */
	start = clock();
	result_b = count_even_single_pass();
	end = clock();
	elapsed_b = (double)(end - start) / (double)CLOCKS_PER_SEC;

	printf("Naive algorithm result: %d\n", result_a);
	printf("Naive algorithm time: %.6f seconds\n", elapsed_a);
	printf("Single-pass algorithm result: %d\n", result_b);
	printf("Single-pass algorithm time: %.6f seconds\n", elapsed_b);

	return (0);
}
