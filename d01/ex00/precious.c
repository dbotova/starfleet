/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 19:03:33 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/21 19:03:34 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *precious(int *text, int size)
{
	char *result = (char*)malloc(sizeof(char) * (size + 1));
	result[size] = 0;
	int str_len = strlen(CS);
	struct s_node *cur = malloc(sizeof(struct s_node));
	cur->c = CS[0];
	cur->next = NULL;
	cur->prev = NULL;

	struct s_node *head = cur;

	for (int i = 1; i < str_len; i++)
	{
		struct s_node *next_n = malloc(sizeof(struct s_node));
		next_n->c = CS[i];
		next_n->prev = cur;
		next_n->next = NULL;
		
		cur->next = next_n;
		cur = next_n;
	}
	cur->next = head;
	head->prev = cur;

	struct s_node *tmp = head;
	for (int i = 0; i < size; i++)
	{
		int n = text[i];
		if (n < 0)
		{
			while (n < 0)
			{
				tmp = tmp->prev;
				n++;
			}
		}
		else
		{
			while (n > 0)
			{
				tmp = tmp->next;
				n--;
			}
		}
		result[i] = tmp->c;
	}
	return (result);
}
