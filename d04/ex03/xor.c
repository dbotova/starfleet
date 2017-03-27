#include "header.h"

char *getXor(char *a, char *b)
{
	char *result = malloc(sizeof(char) * 7);
	result[6] = 0;

	for (int i = 5; i >= 0; i --)
	{
		int first = a[i] - '0';
		int second = b[i] - '0';
		result[i] = (first ^ second) + '0';
	}
	return (result);
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
