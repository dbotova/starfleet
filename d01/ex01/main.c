#include "header.h"

int main(int ac, char **av)
{
	struct s_node *lst;

	lst = createList(av + 1, ac - 1);
	printReverse(lst);

	return (0);
}



// Function used for the test
// Don't go further :)

struct s_node *createList(char **words, int n)
{
	struct s_node *lst;
	struct s_node *tmp;
	int i;

	lst = NULL;
	i = n - 1;
	while (i >= 0) 
	{
		if (!(tmp = (struct s_node *)malloc(sizeof(struct s_node))))
			return (NULL);
		tmp->word = words[i];
		tmp->next = lst;
		lst = tmp;
		i--;
	}
	return (lst);
}
