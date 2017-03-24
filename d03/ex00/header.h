#ifndef HEADER_H
# define HEADER_H
# include <stdio.h> //printf, scanf, ...
# include <string.h> //memcpy, strlen, ...
# include <unistd.h> //fork, write, sleep...
# include <stdlib.h> //malloc, free, exit...
# include <time.h>


struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
};

struct s_info
{
	int min; //the minimum value in the tree
	int max; //the max value in the tree
	int elements; //nombre d'elements
	int depth; //la profondeur de l'arbre
	int isBST; //0 = TRUE, 1 = FALSE
	int isBalanced; //0 = TRUE, 1 = FALSE
};

struct s_info   getInfo(struct s_node *root);

void printBinaryTree(struct s_node * t); //print a binary tree
struct s_node *genRandomBinaryTree(unsigned seed); //gen a random binary tree
void    printTreeInfo(struct s_info info); //print the info from a binary tree

#endif
