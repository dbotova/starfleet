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

	players[a]->score = players[b]->score;
	players[a]->name = strdup(players[b]->name);
	
	players[b]->score = t_score;
	players[b]->name = strdup(t_name);
}

static void sort(struct s_player **players, int size)
{
	if (size < 2)
		return ;

	int pivot = players[size / 2]->score;
	int i = 0;
	int j = 0;

	for (i = 0, j = size - 1; ; i++, j--)
	{
		while(players[i]->score > pivot) i++;
		while(players[j]->score < pivot) j--;

		if (i >= j)
			break;

		swap(players, i, j);
	}

	sort(players, i);
	sort(players + i, size - i);
}

void quickSort(struct s_player **players)
{
	if (!players || !*players)
		return ;

	int size = get_size(players);
	sort(players, size);
}