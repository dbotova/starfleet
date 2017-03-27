#include "header.h"

static void negate(char *str)
{
	for (int i = 1; i < 5; i++)
	{
		if (str[i] == '0')
			str[i] = '1';
		else
			str[i] = '0';
	}
}

char *getAnd(char *a, char *b)
{
	char *result = malloc(sizeof(char) * 5);
	result[4] = 0;

	if (a[0] == '~')
	{
		negate(a);
		a++;
	}
	if (b[0] == '~')
	{
		negate(b);
		b++;
	}

	for (int i = 3; i >= 0; i --)
		result[i] = a[i] & b[i];
	return (result);
}

char *getOr(char *a, char *b)
{
	char *result = malloc(sizeof(char) * 5);
	result[4] = 0;

	if (a[0] == '~')
	{
		negate(a);
		a++;
	}
	if (b[0] == '~')
	{
		negate(b);
		b++;
	}
	 
	for (int i = 3; i >= 0; i --)
		result[i] = a[i] | b[i];
	return (result);
}

int toInt(char *bits)
{
	int result = 0;
	int base = 1; // 2^0

	for (int i = 3; i >= 0; i--)
	{
		result += (bits[i] - '0') * base;
		base *= 2;
	}
	return (result);
}
