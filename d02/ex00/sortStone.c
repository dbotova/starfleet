/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:18:17 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/22 20:18:19 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int get_size(struct s_stone **stone)
{
	int i = 0;

	while (stone[i])
		i++;

	return (i);
} 

static void sort(struct s_stone **stone, int size)
{
	if (size < 2)
		return ;
	int i;
	int j;
	int pivot = stone[size / 2]->size;

	for (i = 0, j = size - 1; ; i++, j--)
	{
		while (stone[i]->size > pivot) i++;
		while (stone[j]->size < pivot) j--;

		if (i >= j)
			break ;

		struct s_stone *tmp = stone[i];
		stone[i] = stone[j];
		stone[j] = tmp;
	}

	sort(stone, i);
	sort(stone + i, size - i);
}

void sortStones(struct s_stone **stone)
{
	if (!stone || !*stone)
		return ;

	int size = get_size(stone);
	sort(stone, size);
}
