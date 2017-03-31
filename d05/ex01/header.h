#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...


struct s_prices
{
	double *items;
	int length;
};

double bestPrice(int pizzaSize, double *prices);

struct s_prices *readList();

#endif
