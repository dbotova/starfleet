#include "header.h"

static int get_size(struct s_player **players)
{
	int i = 0;

	while (players[i]) i++;

	return (i);
}

static int check_time(struct s_player **players, int i, int j)
{
	if (players[i]->score < players[j]->score)
		return (1);
	if (players[i]->score == players[j]->score)
	{
		if (strcmp(players[i]->timeStamp, players[j]->timeStamp) < 0)
			return (1);
	}
	return (0);
}

static void merge(struct s_player **players, int start, int mid, int end)
{
	int m_size = end - start + 1;
	struct s_player **tmp = malloc(sizeof(struct s_player) * m_size);

	int merge_idx = 0;
	int left_idx = start;
	int right_idx = mid + 1;

	while (left_idx <= mid && right_idx <= end)
	{
		if (check_time(players, left_idx, right_idx))
			tmp[merge_idx++] = players[left_idx++];
		else
			tmp[merge_idx++] = players[right_idx++];
	}

	while(left_idx <= mid)
		tmp[merge_idx++] = players[left_idx];
	while(right_idx <= end)
		tmp[merge_idx++] = players[right_idx++];

	for (merge_idx = 0; merge_idx < m_size; ++merge_idx)
		players[start + merge_idx] = tmp[merge_idx];

	free(tmp);
	tmp = NULL;
}

static void split(struct s_player **players, int start, int end)
{
	while (start < end)
	{
		int mid = (start + end) / 2;

		split(players, start, mid);
		split(players, mid + 1, end);
	}
}

struct s_player **mergeSort(struct s_player **players)
{
	if (!players || !*players)
		return (players);

	int size = get_size(players);
	split(players, 0, size);

	return (players);
}