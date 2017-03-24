/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:58:50 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/23 18:58:51 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void countSort(unsigned char *utensils, int n)
{
	long long map[16] = {0};

	for (int i = 0; i < n; i++)
		map[utensils[i]] += 1;

	int i = 0;
	for (int j = 0; j < NUMBER_OF_UTENSILS + 1; j++)
	{
		while (map[j] > 0)
		{
			utensils[i++] = j;
			map[j] -= 1;
		}
	}
}
