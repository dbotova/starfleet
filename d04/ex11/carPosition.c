#include "header.h"

int carPosition(unsigned int parkingRow)
{
	if (!parkingRow)
		return (-1);
	int pos = log2(parkingRow & -parkingRow);

	parkingRow &= ~(1 << pos);

	if (!parkingRow)
		return (pos);

	return (-1);
}
