#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...


struct s_node
{
	char          *word;
	struct s_node *next;
};

void printReverse(struct s_node *lst);
struct s_node *createList(char **words, int n);

#endif
