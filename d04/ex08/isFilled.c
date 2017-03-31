#include "header.h"

int isFilled(unsigned int parkingRow)
{
	unsigned int mask = parkingRow + 1;
	if (parkingRow & mask)
		return (0);
	return (1);
}
