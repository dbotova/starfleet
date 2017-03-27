#include "header.h"

static char *negate(char *str)
{
	char *result = malloc(sizeof(char) * 5);
	for (int i = 1; i < 5; i++)
		result[i - 1] = ~str[i];
	return (result++);
}

char *getAnd(char *a, char *b)
{
	char *result = malloc(sizeof(char) * 5);
	result[4] = 0;

	if (a[0] == '~')
		a = negate(a);
	if (b[0] == '~')
		b = negate(b);

	for (int i = 3; i >= 0; i --)
		result[i] = a[i] & b[i];
	return (result);
}

char *getOr(char *a, char *b)
{
	char *result = malloc(sizeof(char) * 5);
	result[4] = 0;

	if (a[0] == '~')
		a = strcpy(a, negate(a));
	if (b[0] == '~')
		b = negate(b);

	printf("a: %s b: %s\n", a, b);
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
