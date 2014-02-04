/****************************/
/**Ryan Evenstad Homework 2**/
/****************************/

#include "hw4-c.h"

void printData(int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		printf("%s %f %d %s\n", dataSet[i].item, dataSet[i].numFloat, dataSet[i].numInt, dataSet[i].color);
	}
}