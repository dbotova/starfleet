#include "header.h"

struct s_tank *initTank(void)
{
	struct s_tank *tank = malloc(sizeof(struct s_tank));
	tank->stacks = malloc(sizeof(struct s_stack) * TANKS);
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
		if (n > TANKS)
		{
			printf("All reservoirs are full. Burn that energy!\n");
			return ;
		}
		tank->n += 1;
	}
	struct s_elem *new = malloc(sizeof(struct s_elem));
	new->energy = energy;
	tank->stacks[n - 1]->sum += energy;
	if (tank->stacks[tank->n - 1]->elem != NULL)
		new->next = tank->stacks[tank->n - 1]->elem;
	else
		new->next = NULL;
	tank->stacks[tank->n - 1]->elem = new;
	printTank(tank);
}

int tankPop(struct s_tank *tank)
{
	if (tank->n == 1 && tank->stacks[tank->n - 1] == 0)
	{
		printf("We are out of energy, captain!%s\n");
		return(0);
	}

	int top = tank->stacks[tank->n - 1]->elem->energy;
	tank->stacks[n - 1]->sum -= top;
	if (tank->stacks[n - 1]->sum == 0)
		tank->n -= 1;
	tank->stacks[tank->n - 1]->elem = tank->stacks[tank->n - 1]->elem->next;
	printTank(tank);
	return (top);
}

void printTank(struct s_tank *tank)
{
	if (!tank || !tank->stacks[tank->n - 1]->elem)
	{
		printf("Oh no! We lost our tanks!\n");
		return ;
	}

	char *header = "------";
	char *footer = "|    |";
	
	printf("normal");
	for (int i = 1; i < tank->n; i++)
	{
		printf("\tnitro%d", i - 1);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("%s\t", header);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("|%-4d|\t", tank->stacks[i]->sum);
	}
	printf("\n");

	for (int j = 0; j < tank->n; j++)
	{
		printf("|%-4d|\t", tank->stacks[i]->sum);
	}
	printf("\n");
}