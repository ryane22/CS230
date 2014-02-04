#include "HW11-C.h"

int generous(char start[84])
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
		int high=0, highIndex, temp, i;
		for(i=0; i<10; i++)
		{
			temp = current->self->costList[i];
			if(temp > high && temp < 1000000000)
			{
				high = temp;
				highIndex=i;
			}
		}
		globalCost += current->self->costList[highIndex];
		//printf("%s was low with a cost of %d\n", current->self->destList[highIndex], current->self->costList[highIndex]);
		generous(current->self->destList[highIndex]);
	}
}