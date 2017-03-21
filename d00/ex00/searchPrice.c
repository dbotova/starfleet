/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:32:04 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/20 18:32:09 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void sort(struct s_art **arts, int size)
{
	if (size < 2)
		return ;
	int i;
	int j;
	char *pivot = strdup(arts[size / 2]->name);

	for (i = 0, j = size - 1; ; i++, j--)
	{
		while ((strcmp(pivot, arts[i]->name)) > 0) i++;
		while ((strcmp(pivot, arts[j]->name)) < 0) j--;

		if (i >= j)
			break ;

		struct s_art *tmp = arts[i];
		arts[i] = arts[j];
		arts[j] = tmp;
	}

	free(pivot);
	pivot = NULL;

	sort(arts, i);
	sort(arts + i, size - i);
}

static int search(struct s_art **arts, char *name, int size)
{
	int i = 0;
	int j = size - 1;
	int res;

	while (i <= j)
	{
		int k = (i + j) / 2;
		if ((res = strcmp(arts[k]->name, name)) == 0)
			return (k);
		else if (res < 0)
			i = k + 1;
		else
			j = k - 1;
	}
	return (-1);
}

static int get_size(struct s_art **arts)
{
	int i = 0;

	while (arts[i])
		i++;

	return (i);
} 

int  searchPrice(struct s_art **arts, char *name)
{
	int i = 0;
	int size = 0;

	if (!arts || !name)
		return (-1);
	size = get_size(arts);
	sort(arts, size);
	int res = search(arts, name, size);
	if (res > 0)
		return (arts[res]->price);
	else
		return (res);
}
