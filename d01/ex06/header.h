#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...

struct s_city
{
	char *name;
	struct s_city *next;
};

char *NthLastCity(struct s_city *city, int n);
struct s_city *getCities(void);

#endif
