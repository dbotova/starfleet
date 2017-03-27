#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...


char *rightShift(char *bin, int k);
char *leftShift(char *bin, int k);
int toInt(char *bits);

int checkBinary(char *str);


#endif
