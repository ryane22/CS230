#include "HW11-A.h"

int drunkWalk(char start[84])
{
	int stuck = 0;
	//printf("starting at %s\n", start);
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
		//delay
		//clock_t endtime = clock() + 1 * CLOCKS_PER_SEC;
		//while ( ( clock() < endtime ) );
		numWalks++;
		//printf("%d\n", numWalks);
		char dest[84];
		struct doubleLink *current = head;
		while(current != NULL)
		{
			if(!strcmp(current->name, start))
				break;
			else
				current = current->next;
		}
		int i = rand()%10;
		//printf("i = %d\n", i);
		while(!strcmp(current->self->destList[i], ""))
		{
			i = rand()%10;
			stuck++;
			if (stuck == 1000)
			{
				printf("You're stuck!");
				return 0;
			}
			//printf("i = %d\n", i);
		}
		globalCost += current->self->costList[i];
		//printf("going to %s with a cost of %d\n\n", current->self->destList[i], current->self->costList[i]);
		drunkWalk(current->self->destList[i]);
	}
}
