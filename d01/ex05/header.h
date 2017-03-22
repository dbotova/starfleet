#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...
# define MIN_BAR 10
# define MAX_BAR 100
# define CAPACITY 1000

// Tank

struct s_elem
{
    int energy;
    struct s_elem *next;
};

struct s_stack
{
    struct s_elem *elem;
    int sum;
};

struct s_tank
{
    struct s_stack **stacks;
    int n;
};

struct s_tank *initTank(void);

void tankPush(struct s_tank *tank, int energy);

int tankPop(struct s_tank *tank);

void printTank(struct s_tank *tank);

#endif
