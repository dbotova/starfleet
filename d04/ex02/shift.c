#include "header.h"

char *rightShift(char *bin, int k)
{

}

char *leftShift(char *bin, int k)
{

}

int toInt(char *bits)
{
	int result = 0;
	int base = 1; // 2^0

	for (int i = 5; i >= 0; i--)
	{
		result += (bits[i] - '0') * base;
		base *= 2;
	}
	return (result);	
}
