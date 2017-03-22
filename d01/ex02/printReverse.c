/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printReverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:34:11 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/21 20:34:12 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *stackInit(void)
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	if (!stack->item)
		return (NULL);

	struct s_item *top = stack->item;
	stack->item = stack->item->next;

	return (top);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *new = malloc(sizeof(struct s_item));

	new->word = strdup(word);
	new->next = stack->item;
	stack->item = new;
}

void printReverse(struct s_node *lst)
{
	struct s_stack *stack = stackInit();
	struct s_node *tmp = lst;
	struct s_item *top = NULL;

	while(tmp)
	{
		push(stack, tmp->word);
		tmp = tmp->next;
	}
	while ((top = pop(stack)))
		printf("%s ", top->word);
	printf("\n");
}
