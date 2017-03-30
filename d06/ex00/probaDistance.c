#include "header.h"

double probaDistance(double dist, int *locations, int n)
{
	double probobility = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int dif = (locations[i] - locations[j] < 0) ? (locations[i] - locations[j]) * -1 : (locations[i] - locations[j]);
			if (dif > dist)
				probobility += 1 / (double)n;
		}
	}
	return (probobility);
}