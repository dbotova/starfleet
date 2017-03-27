#include "header.h"

// Sum = a XOR b XOR carry
// Carry = (a AND b) OR ( b AND carry ) OR ( carry AND a )

char *getSum(char *a, char *b)
{
	char *result = malloc(sizeof(char) * 7);
	result[6] = 0;
	int carry = 48;
	int i = 5;
	for (; i > 0; i--)
	{
		int first = a[i] - '0';
		int second = b[i] - '0';
		int sum = (first ^ second ^ carry);
		result[i] = sum;
		carry = ((a[i] & b[i]) | (b[i] & carry) | (carry & a[i]));
	}
	if (carry)
		result[i] = carry;
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