/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbotova <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:08:27 by dbotova           #+#    #+#             */
/*   Updated: 2017/03/22 20:08:28 by dbotova          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_queue *queueInit(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void enqueue(struct s_queue *queue, char *content)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->content = strdup(content);
	new->next = queue->first;
	queue->first = new;
	if (queue->last == NULL)
		queue->last = new;
}

char *dequeue(struct s_queue *queue)
{
	char *top = NULL;

	if (queue->first == NULL)
		return (NULL);
	top = queue->first->content;
	struct s_node *tmp = queue->first;
	free(tmp);
	tmp = NULL;
	queue->first = queue->first->next;
	if (queue->first == NULL)
		queue->last = NULL;
	return (top);
}

char *peek(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}
