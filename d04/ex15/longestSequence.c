#include "header.h"

int longestSequence(unsigned int parkingRow)
{
	int count = 0;

	while (parkingRow)
	{
		count++;
		parkingRow &= (parkingRow << 1);
	}

	return (count);
}