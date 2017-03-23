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
	struct s_node *start = NULL;
	struct s_node *end = NULL;
	struct s_node *cur = copy;
	struct s_node *original = node;

	cur->value = original->value;
	original = original->next;

	while (original)
	{
		struct s_node *tmp = malloc(sizeof(struct s_node));
		tmp->value = original->value;

		cur->next = tmp;
		cur = cur->next;
		original = original->next;
		if (!original)
			end = cur;
	}

	return (copy);
}
