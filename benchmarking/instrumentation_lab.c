#include <stdio.h>
#include <time.h>

#define DATASET_SIZE 50000
#define SEED_VALUE 42u

static int dataset[DATASET_SIZE];

static unsigned int next_value(unsigned int *state)
{
	*state = (*state * 1103515245u) + 12345u;
	return (*state);
}

static void build_dataset(void)
{
	unsigned int state;
	int i;

	state = SEED_VALUE;

	for (i = 0; i < DATASET_SIZE; i++)
		dataset[i] = (int)(next_value(&state) % 100000);
}


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


static unsigned long reduce_checksum(void)
{
	unsigned long sum;
	int i;

	sum = 0;
	for (i = 0; i < DATASET_SIZE; i++)
		sum = (sum * 131ul) + (unsigned long)dataset[i];

	return (sum);
}

int main(void)
{
	clock_t t_start, t_build, t_process, t_reduce;
	unsigned long checksum;
	double d_total, d_build, d_process, d_reduce;

	t_start = clock();

	/* Étape Build */
	build_dataset();
	t_build = clock();

	/* Étape Process */
	process_dataset();
	t_process = clock();

	/* Étape Reduce */
	checksum = reduce_checksum();
	t_reduce = clock();

	/* Calculs des durées */
	d_total = (double)(t_reduce - t_start) / CLOCKS_PER_SEC;
	d_build = (double)(t_build - t_start) / CLOCKS_PER_SEC;
	d_process = (double)(t_process - t_build) / CLOCKS_PER_SEC;
	d_reduce = (double)(t_reduce - t_process) / CLOCKS_PER_SEC;

	if (checksum == 0ul)
		printf("impossible\n");

	/* Affichage formaté */
	printf("TOTAL seconds: %f\n", d_total);
	printf("BUILD_DATA seconds: %f\n", d_build);
	printf("PROCESS seconds: %f\n", d_process);
	printf("REDUCE seconds: %f\n", d_reduce);

	return (0);
}
