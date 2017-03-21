#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h>

/*--------------------------------
  !! required structure
--------------------------------*/

struct  s_art 
{
    char *name;
    int price;
};


int  searchPrice(struct s_art **arts, char *name);
struct s_art		**getArts(void);

#endif
