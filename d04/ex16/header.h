#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...


struct s_bit
{
	int *arr;
	int n;
};

int	**pianoDecompress(struct s_bit *bit, int l);

void		getPianoFile(char *filename, struct s_bit **bit, int *l);
void		printPianoUncompressed(int **m, int l);

#endif
