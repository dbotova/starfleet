/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printReverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 20:11:51 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/21 20:11:53 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printReverse(struct s_node *lst)
{
	if (!lst)
		return ;
	printReverse(lst->next);
	
	if (lst->next)
		printf(" ");
	printf("%s", lst->word);

	if (!lst)
		printf("\n");
}