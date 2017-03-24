/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:18:04 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/24 11:18:06 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
# define ABS(x) (x < 0) ? x : -x
# define MAX(x, y) (x > y) ? x : y

static int getHeight(struct s_node *root)
{
	if (!root)
		return (0);
	else
		return (MAX(getHeight(root->left), getHeight(root->right)) + 1);
}

static int travelTree(struct s_node *root, struct s_info *info)
{
	if (!root)
		return 0;

	info->elements += 1;
	if (root->value > info->max)
		info->max = root->value;
	if (root->value < info->min)
		info->min = root->value;
	if (root->left && root->right &&
		root->left->value > root->right->value)
		info->isBST = 1;
	if (root->left && root->right && 
		(root->value < root->left->value || root->value > root->right->value))
		info->isBST = 1;

	int h_dif = getHeight(root->right) - getHeight(root->left);

	if (ABS(h_dif) > 1)
		info->isBalanced = 1;

	int ldepth = travelTree(root->left, info);
	int rdepth = travelTree(root->right, info);

	 if (ldepth > rdepth) 
           return(ldepth+1);
     else
       	return(rdepth+1);
}

struct s_info   getInfo(struct s_node *root)
{
	struct s_node *tmp = NULL;
	struct s_info *info = malloc(sizeof(struct s_info));

	info->min = root->value;
	info->max = root->value;
	info->isBalanced = 0;
	info->isBST = 0;
	info->depth = 0;
	info->elements = 0;

	if (!root)
		return (*info);

	info->depth = travelTree(root, info) - 1;

	return (*info);
}
