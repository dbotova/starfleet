/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyGameBoard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:02:14 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/22 17:02:15 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *copy = malloc(sizeof(struct s_node));
	struct s_node *start = copy;
	struct s_node *cur = copy;
	struct s_node *original = node;

	cur->value = original->value;
	original = original->next;

	while (original)
	{
		struct s_node *tmp = malloc(sizeof(struct s_node));
		tmp->value = original->value;
		tmp->random = NULL;

		cur->next = tmp;
		cur = cur->next;
		original = original->next;
	}
	cur->next = NULL;
	cur = copy;
	original = node;

	while (cur)
	{
		struct s_node *tmp = start;

		if (original->random == NULL)
			cur->random = NULL;
		else if (original->random->value == original->value)
			cur->random = cur;
		else while (tmp && tmp->value != original->random->value)
		{
			tmp = tmp->next;
		}
		if (original->random && original->random->value != original->value)
			cur->random = tmp;

		cur = cur->next;
		original = original->next;
	}

	return (copy);
}
