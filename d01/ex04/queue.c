#include "header.h"

struct s_queue *queueInit(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

char *dequeue(struct s_queue *queue)
{
	char *top = NULL;

	if (queue->first == NULL)
		return (NULL);
	top = queue->first->message;
	struct s_node *tmp = queue->first;
	free(tmp);
	tmp = NULL;
	queue->first = queue->first->next;
	if (queue->first == NULL)
		queue->last = NULL;
	return (top);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->message = strdup(message);
	new->next = queue->first;
	queue->first = new;
	if (queue->last == NULL)
		queue->last = new;
}

char *peek(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}