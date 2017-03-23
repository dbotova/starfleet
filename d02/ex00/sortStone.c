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

static void swap(struct s_stone **cur)
{
	struct s_stone *tmp = *cur;

	*cur = (*cur)->next;
	tmp->next = (*cur)->next;
	(*cur)->next = tmp;
}

static int get_size(struct s_stone *stone)
{
	struct s_stone *tmp = stone;
	int i = 0;

	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void sortStones(struct s_stone **stone)
{
	struct s_stone **j = NULL;
	int size  = get_size(*stone);

	while (size)
	{
		j = stone;
		while(*j) 
		{
			while (*j && (*j)->next && (*j)->size == (*j)->next->size)
				j = &((*j)->next);
			if((*j)->next && (*j)->size > (*j)->next->size)
				swap(j);
			j = &((*j)->next);
		}
		size--;
	}
}
