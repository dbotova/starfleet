#include "header.h"

int main(int ac, char **av)
{
	unsigned int parkingRow;
	int pos;

	if (ac == 3 && (pos = atoi(av[2])) >= 0 && pos < 20) {
		parkingRow = atoi(av[1]);
	}else{
		printf("usage: ./getPlace parkingRow pos\n");
		return (0);
	}

	printf("Parking place %d: %s\n", pos, (getPlace(parkingRow, pos)) ? "occupied" : "vacant");

	return (0);
}



// Function used for the test
// Don't go further :)

