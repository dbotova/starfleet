#include "header.h"

int occupiedPlaces(unsigned int parkingRow)
{
	int res = 0;
	while (parkingRow)
	{
		parkingRow &= parkingRow - 1;
		res++;
	}
	return (res);
}
