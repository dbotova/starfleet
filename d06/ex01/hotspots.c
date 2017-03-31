#include "header.h"
# define SIZE 20 

struct s_spot
{
	struct s_spot *prev;
	struct s_spot *next;
	struct s_spot *in_range;
	int value;
	int is_spot;
};

struct s_map
{
	int size;
	int start;
	int end;
	struct s_spot **spots;
};

static struct s_map *initMap()
{
	struct s_map *map = malloc(sizeof(struct s_map));
	map->size = SIZE;
	map->start = -1;
	map->end = -1;
	map->spots = malloc(sizeof(struct s_spot) * SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		map->spots[i] = malloc(sizeof(struct s_spot));
		map->spots[i]->prev = NULL;
		map->spots[i]->next = NULL;
		map->spots[i]->in_range = NULL;
		map->spots[i]->value = i;
		map->spots[i]->is_spot = 0;
	}
	return (map);
}

static int count_spots(struct s_map *map)
{
	int count = 0;
	struct s_spot *tmp = map->spots[map->start];

	while (tmp->value < map->end)
	{
		if (!tmp->next || !tmp->in_range || (tmp->in_range->value <= tmp->value && !tmp->next))
		{
			int next = tmp->value + 1;
			while (!map->spots[next]->is_spot) next++;
			tmp = map->spots[next];
		}
		if (tmp->is_spot)
			count++;

		if (tmp->next)
			tmp = tmp->next;
		else if (tmp->in_range && tmp->in_range->value > tmp->value)
			tmp = tmp->in_range;
	}
	return (count);
}

int selectHotspots(struct s_hotspot **hotspots)
{
	if (!hotspots || !*hotspots)
		return 0;

	
	struct s_map *map = initMap();
	map->start = hotspots[0]->pos;

	for (int i = 0; hotspots[i]; i++)
	{
		if (!hotspots[i + 1])
			map->end = hotspots[i]->pos;

		map->spots[hotspots[i]->pos]->value = hotspots[i]->pos;
		map->spots[hotspots[i]->pos]->is_spot = 1;
		if (hotspots[i]->pos > map->size || hotspots[i]->pos + hotspots[i]->radius > map->size)
		{
			map->size *= 2;
			map = realloc(map, map->size);
		}

		if (map->spots[hotspots[i]->pos]->in_range && map->spots[hotspots[i]->pos]->in_range->next->value > hotspots[i]->pos + hotspots[i]->radius)
			continue ;

		map->spots[hotspots[i]->pos] = map->spots[hotspots[i]->pos];
		if (hotspots[i]->pos - hotspots[i]->radius > 0)
		{
			map->spots[hotspots[i]->pos - hotspots[i]->radius]->next = map->spots[hotspots[i]->pos];
			map->spots[hotspots[i]->pos]->prev = map->spots[hotspots[i]->pos - hotspots[i]->radius];
		}
		map->spots[hotspots[i]->pos + hotspots[i]->radius]->prev = map->spots[hotspots[i]->pos];
		map->spots[hotspots[i]->pos]->next = map->spots[hotspots[i]->pos + hotspots[i]->radius];

		for (int x = hotspots[i]->pos - hotspots[i]->radius; x <= hotspots[i]->pos + hotspots[i]->radius; x++)
		{
			if (x >= map->start)
				map->spots[x]->in_range = map->spots[hotspots[i]->pos];
		}
	}
	return (count_spots(map));
}
