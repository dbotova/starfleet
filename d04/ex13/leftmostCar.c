#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	if (!parkingRow)
		return (-1);

	int pos = 0;
	while (parkingRow != 1)
	{
		parkingRow >>= 1;
		pos++;
	}
	return (pos);
}
