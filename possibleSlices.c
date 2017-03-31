#include "header.h"

static void get_terms(struct s_array *arr, int pizzaSize, int term, int *step)
{
	if (!term)
	{
		*step = 0;
		return ;
	}
	if (*step)
		get_terms(arrayInit(), pizzaSize, term - 1, step);
	arrayAppend(arr, term);
	if (arr->sum < pizzaSize)
	{
		for (int i = pizzaSize; i > 0; i--)
			get_terms(arrayClone(arr), pizzaSize, i, step);
	}
	else if (arr->sum == pizzaSize)
		arrayPrint(arr);
}

void printPossibleSlices(int pizzaSize)
{
	int step = 1;
	get_terms(arrayInit(), pizzaSize, pizzaSize, &step);
}
