#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...
# include <time.h>
# include <ctype.h>

struct s_node
{
	int value;
	int isFinal;
	struct s_node *random;
	struct s_node *next;
};

int	minimumMoves(struct s_node *begin); //you must return the minimum number of strokes to access to the final

struct s_node *getBoardFromFile(char *file);

#endif
