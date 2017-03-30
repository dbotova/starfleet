#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	if (!hotspots || !*hotspots)
		return 0;

	int count = 0;
	int start = hotspots[0]->pos;
	int end = hotspots[0]->radius;
	int i = 0;
	for (; hotspots[i]; i++)
	{
		if (i && end - hotspots[i]->radius >= hotspots[i - 1]->radius)
			count--;
		if (hotspots[i]->radius >= hotspots[i]->pos - end)
		{
			end = hotspots[i]->pos + hotspots[i]->radius;
			count++;
			printf("covered: form %d to %d\n", start, end);
		}

	}
	
	return (count);
}
