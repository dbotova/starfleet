#include "header.h"

static void swap(struct s_player **players, int a, int b)
{
	int t_score = players[a]->score;
	char *t_name = players[a]->name;

	players[a]->score = players[b]->score;
	players[a]->name = strdup(players[b]->name);
	
	players[b]->score = t_score;
	players[b]->name = strdup(t_name);
}

static int get_size(struct s_player **players)
{
	int i = 0;

	while (players[i]) i++;
	return (i);
}

void insertionSort(struct s_player **players)
{
	if (!players || !*players)
		return ;

	int size = get_size(players);
	int b = 1;
	int cur = 1;

	while(b < size)
	{
		cur = b;
		if (players[cur]->score > players[cur - 1]->score)
		{
			while (cur > 0 && players[cur - 1]->score < players[cur]->score)
			{
				swap(players, cur, cur - 1);
				cur--;
			}
		}
		b++;
	}
}