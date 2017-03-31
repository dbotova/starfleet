#include "header.h"

int carPosition(unsigned int parkingRow)
{
	if (!parkingRow)
		return (-1);
	int i = 0;

	for (; parkingRow; i++)
	{
		int bit = (parkingRow >> i) & 1;
		if (bit)
			break ;
	}
	parkingRow &= ~(1 << i);
	if (!parkingRow)
		return (i);
	return (-1);
}
