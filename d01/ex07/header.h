#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...
# include <time.h>

struct s_node
{
	int value;
	struct s_node *random;
	struct s_node *next;
};

struct s_node *cloneGameBoard(struct s_node *node);

struct s_node *genRandomSnakesAndLadders(int n);
void    printSnakeAndLadders(struct s_node *node);

#endif
