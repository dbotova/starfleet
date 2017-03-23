/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:04:31 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/22 20:04:32 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node *clone_list(struct s_node *node)
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
		tmp->other = NULL;

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

		if (original->other == NULL)
			cur->other = NULL;
		else if (original->other->value == original->value)
			cur->other = cur;
		else while (tmp && tmp->value != original->other->value)
		{
			tmp = tmp->next;
		}
		if (original->other && original->other->value != original->value)
			cur->other = tmp;

		cur = cur->next;
		original = original->next;
	}

	return (copy);
}
