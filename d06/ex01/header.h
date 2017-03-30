#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...

struct s_hotspot
{
	int pos;
	int radius;
};


int selectHotspots(struct s_hotspot **hotspots);

struct s_hotspot **readHotspots(char *filename);

#endif
