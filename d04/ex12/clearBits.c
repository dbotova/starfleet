#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
	
	while (n)
	{
		parkingRow &= ~(1 << (n - 1));
		n--;
	}
	
	return (parkingRow);
}
