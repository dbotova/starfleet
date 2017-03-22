#include "header.h"

static void test(struct s_tank *tank)
{
	tankPush(tank, 10);
	tankPush(tank, 20);
	tankPush(tank, 30);
	printf("\npoped: %d\n", tankPop(tank));
	tankPush(tank, 40);
	tankPush(tank, 50);
	tankPush(tank, 60);
	tankPush(tank, 70);
	tankPush(tank, 80);
	tankPush(tank, 90);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 15);
	tankPush(tank, 25);
	tankPush(tank, 35);
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 80);
	tankPush(tank, 90);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 80);
	tankPush(tank, 100);
	tankPush(tank, 10);
	tankPush(tank, 100);
	tankPush(tank, 70);
	tankPush(tank, 80);
	tankPush(tank, 90);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 100);
	tankPush(tank, 15);
	tankPush(tank, 25);
	tankPush(tank, 35);
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
	printf("\npoped: %d\n", tankPop(tank));
}

int main(void)
{
	struct s_tank *tank = initTank();

	while (42)
	{
		char input[15];
		int energy = 0;

		printf("(''):");
		scanf("%s", input);

		if (strcmp(input, "exit") == 0)
			break ;
		if (strcmp(input, "pop") == 0)
			tankPop(tank);
		else if (strcmp(input, "push") == 0)
		{
			scanf("%d", &energy);
			tankPush(tank, energy);
		}
		else if (strcmp(input, "print") == 0)
			printTank(tank);
		else if (strcmp(input, "test") == 0)
			test(tank);
		else
			printf("Try again\n");
	}
	
	return (0);
}

