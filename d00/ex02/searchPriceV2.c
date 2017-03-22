/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 22:46:58 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/20 22:46:59 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int searchPrice(struct s_art **arts, char *name)
{
	int size = get_size(arts);
	if (!arts || !name)
		return (-1);
	int res = search(arts, name, size);
	if (res > 0)
		return (arts[res]->price);
	else
		return (res);
}