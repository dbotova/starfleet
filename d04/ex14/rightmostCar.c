#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	if (!parkingRow)
		return (-1);
	int pos = 0;
	while (((parkingRow >> 0) & 1) != 1)
	{
		pos++;
		parkingRow >>= 1;
	}
	return (pos);
}
