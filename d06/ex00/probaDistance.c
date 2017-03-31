#include "header.h"

double probaDistance(double dist, int *locations, int n)
{
	if (n < 2)
        return (0);

    int left = 0;
    int right = 0;
    int count = 0;
  
    while (left < n)
    {
        if (right <= left)
            right = left + 1;
        while (right < n && locations[right] - locations[left] <= dist)
            right++;
        count += n - right;
        left++;
    }
    return (((double)count * 2 / (double)(n * (n - 1))));
}