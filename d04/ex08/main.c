#include "header.h"

int main(int ac, char **av)
{
	unsigned int parkingRow;

	if (ac == 2) {
		parkingRow = atoi(av[1]);
	}else{
		printf("usage: ./isFilled parkingRow\n");
		return (0);
	}

	printf("Parking row %d is%s filled from right to left\n", parkingRow, (isFilled(parkingRow)) ? "" : " not");

	return (0);
}



// Function used for the test
// Don't go further :)

