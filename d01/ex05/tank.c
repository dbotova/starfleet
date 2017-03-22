#include "header.h"

struct s_tank *initTank(void)
{
	struct s_tank *tank = malloc(sizeof(struct s_tank));
	//tank->stacks = malloc(sizeof(struct s_stack) * TANKS);
	tank->stacks = malloc(sizeof(struct s_stack));
	tank->stacks[0] = malloc(sizeof(struct s_stack));
	tank->stacks[0]->elem = NULL;
	tank->stacks[0]->sum = 0;
	tank->n = 1;
	return (tank);
}

void tankPush(struct s_tank *tank, int energy)
{
	if (energy < MIN_BAR || energy > MAX_BAR)
	{
		printf("Energy bar must be between %d and %d units\n", MIN_BAR, MAX_BAR);
		return ;
	}
	if (tank->stacks[tank->n - 1]->sum + energy > CAPACITY)
	{
		// if (tank->n > TANKS)
		// {
		// 	printf("All reservoirs are full. Burn that energy!\n");
		// 	return ;
		// }
		tank->n += 1;
		tank->stacks = realloc(tank->stacks, tank->n);
		tank->stacks[tank->n - 1] = malloc(sizeof(struct s_stack));
	}
	tank->stacks[tank->n - 1]->sum += energy;

	struct s_elem *new = malloc(sizeof(struct s_elem));
	new->energy = energy;
	new->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = new;

	printTank(tank);
}

int tankPop(struct s_tank *tank)
{
	if (tank->n == 1 && tank->stacks[tank->n - 1]->sum == 0)
	{
		printf("We are out of energy, captain!\n");
		return(0);
	}

	struct s_elem *tmp = tank->stacks[tank->n - 1]->elem;
	int top = tmp->energy;
	tank->stacks[tank->n - 1]->sum -= top;
	if (tank->stacks[tank->n - 1]->sum == 0 && tank->n > 1)
		tank->n -= 1;
	tank->stacks[tank->n - 1]->elem = tank->stacks[tank->n - 1]->elem->next;

	printTank(tank);

	free(tmp);
	tmp = NULL;

	return (top);
}

void printTank(struct s_tank *tank)
{
	if (!tank)
	{
		printf("Oh no! We lost our tanks!\n");
		return ;
	}
	
	char *header = "------";
	char *footer = "|    |";
	
	printf("\nnormal");
	for (int i = 1; i < tank->n; i++)
	{
		printf("\tnitro%d", i);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("%s\t", header);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("|%-4d|\t", tank->stacks[j]->sum);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("%s\t", footer);
	}
	printf("\n\n");
}	

