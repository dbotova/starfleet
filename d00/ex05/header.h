#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...
# define MIN_LENGTH 4
# define MAP_SIZE 100000

struct s_elem 
{
	char *word;
	int  occurence;
};

struct s_list
{
	struct s_elem **elems;
	int len;
};

char **mostUsedWords(char *book);
char *readFile(void);
void strip_str(char *str);

#endif
