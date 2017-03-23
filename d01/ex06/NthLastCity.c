/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NthLastCity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:53:31 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/22 15:53:32 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *NthLastCity(struct s_city *city, int n)
{
	if (!city || n < 0)
		return (NULL);

    struct s_city *p1 = city;
    struct s_city *p2 = city;

    for (int i = 0; i < n + 1; i++)
    {
    	p2 = p2->next;
    	if (!p2 && i == n)
    		return (p1->name);
    	if (!p2 && i < n + 1)
    		return (NULL);
    }

    if (!p2)
    	return (p1->name);

 	while (p2)
 	{
 		p1 = p1->next;
 		p2 = p2->next;
 	}

    return (p1->name);
}
