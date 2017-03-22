#include "header.h"

int main(void)
{
	struct s_queue *queue = queueInit();
	printf("is empty? %d\n", isEmpty(queue));
	printf("peek %s\n", peek(queue));
	enqueue(queue, "first");
	enqueue(queue, "second");
	printf("first: %s last: %s\n", queue->first->message, queue->last->message);
	dequeue(queue);
	printf("first: %s last: %s\n", queue->first->message, queue->last->message);
	enqueue(queue, "hello");
	dequeue(queue);
	printf("is empty? %d\n", isEmpty(queue));
	printf("peek %s\n", peek(queue));

	return (0);
}


