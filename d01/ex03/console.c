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
		return (0);

	struct s_item *top = stack->item;
	stack->item = stack->item->next;

	return (top->idx);
}

char *console(void)
{
	char *message = (char*)malloc(sizeof(char) * 256);
	memset(message, 0, 256);
	//int start = 0;
	int i = 0;

	struct s_stack *stack = initStack();

	while(42)
	{
		char *input = (char*)malloc(sizeof(char) * 256);
		memset(input, 0, 256);
		printf("(''):");
		scanf("%[^\n]", input);

		if (strcmp(input, "SEND") == 0)
			break ;

		if (i > 0)
			message[i++] = ' ';
		if (strcmp(input, "UNDO") != 0)
		{
			push(stack, i);
			for (int a = 0; ; a++)
			{
				if (input[a] == 0)
					break ;
				message[i++] = input[a];
			}
		}
		else
		{
			i = pop(stack);
			message[i] = 0;
		}

		printf("%s\n", message);
	}
	return (message);
}
