#include "header.h"

int main(int ac, char **av)
{
	unsigned int parkingRow;

	if (ac == 2) {
		parkingRow = atoi(av[1]);
	}
	else
	{
		printf("usage: ./carPosition parkingRow\n");
		return (0);
	}

	printf("Parking row %d has 1 car at position %d\n", parkingRow, carPosition(parkingRow));

	return (0);
}



// Function used for the test
// Don't go further :)

