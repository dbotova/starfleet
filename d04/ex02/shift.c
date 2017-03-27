#include "header.h"

char *rightShift(char *bin, int k)
{
	char *result = malloc(sizeof(char) * 7);
	result[6] = 0;
	int i = 0;

	while (k)
	{
		result[i++] = bin[0];
		k--;
	}
	for (int j = 0; i < 6; i++, j++)
		result[i] = bin[j];
	return (result);
}

char *leftShift(char *bin, int k)
{
	char *result = malloc(sizeof(char) * 7);
	result[6] = 0;
	int i = 5;

	while (k)
	{
		result[i--] = '0';
		k--;
	}
	for (int j = 5; i >= 0; i--, j--)
		result[i] = bin[j];
	return (result);
}

static int neg_toInt(char *bits)
{
	for (int i = 0; i < 6; i++)
	{
		if (bits[i] == '0')
			bits[i] = '1';
		else
			bits[i] = '0';
	}

	int result = 0;
	int base = 1; // 2^0

	for (int i = 5; i >= 0; i--)
	{
		result += (bits[i] - '0') * base;
		base *= 2;
	}

	return ((result * -1) -1);
}

int toInt(char *bits)
{
	int result = 0;
	int base = 1; // 2^0

	if (bits[0] == '1')
		return (neg_toInt(bits));
	for (int i = 5; i >= 0; i--)
	{
		result += (bits[i] - '0') * base;
		base *= 2;
	}
	return (result);	
}
