#include "header.h"

static int get_size(struct s_player **players)
{
	int i = 0;

	while (players[i]) i++;

	return (i);
}

static void swap(struct s_player **players, int a, int b)
{
	int t_score = players[a]->score;
	char *t_name = players[a]->name;
	char *t_time = players[a]->timeStamp;

	players[a]->score = players[b]->score;
	players[a]->name = strdup(players[b]->name);
	players[a]->timeStamp = strdup(players[b]->timeStamp);
	
	players[b]->score = t_score;
	players[b]->name = strdup(t_name);
	players[b]->timeStamp = strdup(t_time);
}

static int check_time(struct s_player **players, int i, int j)
{
	if (players[i]->score < players[j]->score)
	{
		printf("i: %d j: %d\n", players[i]->score, players[j]->score);
		swap(players, i, j);
		printPlayers(players);
		return (1);
	}
	if (players[i]->score == players[j]->score)
	{
		if (strcmp(players[i]->timeStamp, players[j]->timeStamp) < 0)
		{
			printf("i: %d j: %d\n", i, j);
			swap(players, i, j);
			printPlayers(players);
			return (1);
		}
	}
	return (0);
}

static void merge(struct s_player **players, int size, int start)
{
	if (size < 2)
		return ;

	int i = start;
	int j = size / 2;

	printf("\nNEW RUN: i: %d j: %d\n", i , j);
	getchar();

	merge(players, j, i);
	check_time(players, i, j);

	//merge(players, size, j);

	// check_time(players, i, j);

	// for ( ; i < size; i++)
	// {
	// 	if (check_time(players, i, j))
	// 		j++;
	// }

}

struct s_player **mergeSort(struct s_player **players)
{
	if (!players || !*players)
		return (players);

	int size = get_size(players);
	merge(players, size, 0);

	return (players);
}