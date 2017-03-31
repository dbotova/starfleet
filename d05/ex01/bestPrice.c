#include "header.h"

static void get_sums(double *sums, int idx, int pizzaSize, int term, int *step, double *prices)
{
	if (!term)
	{
		printf("step 0\n");
		*step = 0;
		return ;
	}
	if (*step)
	{
		printf("step 1 idx: %d\n", idx);
		get_sums(sums, idx + 1, pizzaSize, term - 1, step, prices);
	}
	sums[idx] += prices[term];
	printf("term: %d idx: %d\n", term, idx);
		getchar();
	if (term < pizzaSize)
	{
		printf("step 2 sum: %f\n", sums[idx]);
		for (int i = pizzaSize; i > 0; i--)
			get_sums(sums, idx, pizzaSize, i, step, prices);
	}
}

double bestPrice(int pizzaSize, double *prices)
{
	int step = 1;
	double *sums = malloc(sizeof(double) * 100);
	memset(sums, 0, sizeof(double) * 100);
	for (int i = 0; i <= pizzaSize; i++)
		printf("price of %d: %f\n", i, prices[i]);

	get_sums(sums, 0, pizzaSize, pizzaSize, &step, prices);
	double winner = 0;
	for (int i = 0; sums[i] > 0; i++)
	{
		if (sums[i] > winner)
			winner = sums[i];
	}
	free(sums);
	return (winner);
}
