#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...
# include <time.h>

struct s_player
{
	int   score;
	char  *name;
};

void insertionSort(struct s_player **players);


struct s_player **genRandomPlayers(int n);
struct s_player *createRandomPlayer(char *name);
void printPlayers(struct s_player **players);

#endif
