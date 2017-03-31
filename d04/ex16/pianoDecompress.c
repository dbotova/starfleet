#include "header.h"

int	**pianoDecompress(struct s_bit *bit, int l)
{
	int **song = malloc(sizeof(int*) * bit->n);
	for (int x = 0; x < l; x++)
		song[x] = malloc(sizeof(int) * l);

	for (int y = bit->n - 1; y >= 0; y--)
	{
		for (int i = 0; i < l; i++)
		{
			song[y][i] = (bit->arr[y] >> 0) & 1;
			bit->arr[y] >>= 1;
		}
	}

	// for (int a = 0; a < bit->n; a++)
	// {
	// 	for (int b = 0; b < l; b++)
	// 		printf("%d ", song[a][b]);
	// 	printf("\n");
	// }
	return (song);
}
