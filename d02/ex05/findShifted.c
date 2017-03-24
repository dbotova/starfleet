/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 20:05:17 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/23 20:05:18 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int binarySearch(int *rocks, int value, int start, int end)
{
	int i = start;
	int j = end + 1;

	while (i <= j)
	{
		int k = (i + j) / 2;
		if (rocks[k] == value)
			return (k);
		else if (rocks[k] < value)
			i = k + 1;
		else
			j = k - 1;
	}
	return (-1);
}

static int shiftedBinarySearch(int *rocks, int start, int end, int value)
{
	int mid = start + (end - start) / 2;

	if ((start == end && rocks[start] != value ) ||
		(start == mid && rocks[start] != value && rocks[end] != value))
		return (-1);
	if (rocks[start] == rocks[mid] == rocks[end] && rocks[start] != value)
		return (shiftedBinarySearch(rocks, mid, end, value)); 

	if (rocks[mid] == value)
		return (mid);
	if (rocks[mid] < rocks[end] &&
		((value >= rocks[mid] && value <= rocks[end]) || rocks[start] == rocks[mid]))
		return (binarySearch(rocks, value, mid, end));
	if (rocks[mid] < rocks[end] &&
		((!(value >= rocks[mid] && value <= rocks[end])) || rocks[start] == rocks[mid]))
		return (shiftedBinarySearch(rocks, start, mid, value));
	if (rocks[start] < rocks[mid] &&
		((value >= rocks[start] && value <= rocks[mid]) || rocks[end] == rocks[mid]))
		return (binarySearch(rocks, value, start, mid));
	else
		return (shiftedBinarySearch(rocks, mid, end, value));
	return (-1);
}

int	searchShifted(int *rocks, int length, int value)
{
	return (shiftedBinarySearch(rocks, 0, length - 1, value));
}
