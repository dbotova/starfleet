/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:33:36 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/21 21:33:38 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack *initStack()
{
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->item = NULL;
	return (stack);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *new = malloc(sizeof(struct s_item));

	new->idx = idx;
	new->next = stack->item;
	stack->item = new;
}

int pop(struct s_stack *stack)
{
	if (!stack->item)
		return (-1);

	struct s_item *top = stack->item;
	stack->item = stack->item->next;

	return (top->idx);
}

char *console(void)
{
	char *message = (char*)malloc(sizeof(char) * 256);
	memset(message, 0, 256);
	int i = 0;

	struct s_stack *stack = initStack();

	while(42)
	{
		size_t bufsize = 256;
		ssize_t msg_size = 0;
		char *input = NULL;
		printf("(''):");
		msg_size = getline(&input, &bufsize, stdin);
		if (msg_size <= 0)
			exit(1);
		else
			input[--msg_size] = 0;

		if (strcmp(input, "SEND") == 0)
			break ;

		if (i > 0)
		{
			strcat(message, " ");
			i++;
		}
		if (strcmp(input, "UNDO") != 0)
		{
			push(stack, i);
			strcat(message, input);
			i += msg_size;
		}
		else
		{
			i = pop(stack);
			if (i < 0)
				i = 0;
			message[i] = 0;
		}

		printf("%s\n", message);
		free(input);
		input = NULL;
	}
	return (message);
}
