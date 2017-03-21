/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 22:35:33 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/20 22:35:37 by dbotova          ###   ########.fr       */
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

static int get_size(struct s_art **arts)
{
	int i = 0;

	while (arts[i])
		i++;

	return (i);
} 

void  sortArts(struct s_art **arts)
{
	int size = get_size(arts);
	sort(arts, size);
}