#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

/**
 * next_value - Generates a pseudo-random value.
 * @state: Pointer to the current state.
 *
 * Return: The next pseudo-random value.
 */
static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

/**
 * build_dataset - Populates the dataset with values.
 */
static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}

/**
 * process_dataset - Performs mathematical operations on the dataset.
 */
static void process_dataset(void)
{
	int i;
	int v;

	for (i = 0; i < DATASET_SIZE; i++)
	{
		v = dataset[i];
		v = (v * 3) + (v / 7) - (v % 11);
		if (v < 0)
			v = -v;
		dataset[i] = v;
	}
}

/**
 * reduce_checksum - Calculates a checksum for the dataset.
 *
 * Return: The calculated checksum.
 */
static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

/**
 * main - Entry point, benchmarks dataset operations.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	unsigned long checksum;
	clock_t start_total, end_total;
	clock_t s_build, e_build;
	clock_t s_process, e_process;
	clock_t s_reduce, e_reduce;

	start_total = clock();

	s_build = clock();
	build_dataset();
	e_build = clock();

	s_process = clock();
	process_dataset();
	e_process = clock();

	s_reduce = clock();
	checksum = reduce_checksum();
	e_reduce = clock();

	end_total = clock();

	if (checksum == 0ul)
		printf("impossible\n");

    printf("TOTAL seconds: %.6f\n", (double)(end_total - start_total) / CLOCKS_PER_SEC);
    printf("BUILD_DATA seconds: %.6f\n", (double)(e_build - s_build) / CLOCKS_PER_SEC);
    printf("PROCESS seconds: %.6f\n", (double)(e_process - s_process) / CLOCKS_PER_SEC);
    printf("REDUCE seconds: %.6f\n", (double)(e_reduce - s_reduce) / CLOCKS_PER_SEC);


	return (0);
}
