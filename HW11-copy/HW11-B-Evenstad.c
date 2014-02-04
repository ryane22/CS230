#include "HW11-B.h"

int greedy(char start[84])
{
	int stuck = 0;
	if(!strcmp(start, "Home"))
	{
		return 1;
	}
	else if(numWalks == 10000)
	{
		printf("You've taken 10,000 walks and run out of hope (infinite loop)...\n");
		return 0;
	}
	else
	{
		numWalks++;
		char dest[84];
		struct doubleLink *current = head;
		while(current != NULL)
		{
			if(!strcmp(current->name, start))
				break;
			else
				current = current->next;
		}
		int low=1000000, lowIndex, temp, i;
		for(i=0; i<10; i++)
		{
			temp = current->self->costList[i];
			if(temp < low)
			{
				low = temp;
				lowIndex=i;
			}
		}
		globalCost += current->self->costList[lowIndex];
		//printf("%s was low with a cost of %d\n", current->self->destList[lowIndex], current->self->costList[lowIndex]);
		greedy(current->self->destList[lowIndex]);
	}
}
