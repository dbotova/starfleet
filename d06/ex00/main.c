#include "header.h"

int main(int ac, char **av)
{
	int *arr;
	int n;
	int dist;

	if (ac >= 4){
		dist = atoi(av[1]);
		n = ac-2;
		arr = malloc(sizeof(int) * (n));
		for (int i = 2; i < ac; i++){
			arr[i-2] = atoi(av[i]);
		}
	}
	else {
		printf("Usage: ./distance dist nb1 nb2 ...\n");
		return (0);
	}
	
	printf("%lf\n", probaDistance(dist, arr, n));

	return (0);
}



// Function used for the test
// Don't go further :)

