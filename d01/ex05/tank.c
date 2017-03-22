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
	new->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = new;
}

int tankPop(struct s_tank *tank)
{
	if (tank->stacks[n - 1]->elem->sum == 0)
	{
		if (tank->n == 1)
		{
			printf("We are out of energy, captain!%s\n");
			return(0);
		}
		tank->n -= 1;
	}
}