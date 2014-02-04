/****************************/
/**Ryan Evenstad Homework 2**/
/****************************/

#include "hw4-b.h"

void sortByInt(int size, int selection)
{
	printf("selection is %d\n", selection);
	int i, j;
	char tempA[20], tempD[20];
	char operator;
	float tempB;
	int tempC;
	if (selection == 3)
	{
		for (i=1; i<size; i++)
		{
			j=i;;
			while (j>0 && dataSet[j-1].numInt < dataSet[j].numInt)
			{
				strcpy(tempA, dataSet[j].item);
				tempB = dataSet[j].numFloat;
				tempC = dataSet[j].numInt;
				strcpy(tempD, dataSet[j].color);
				
				strcpy(dataSet[j].item, dataSet[j-1].item);
				dataSet[j].numFloat = dataSet[j-1].numFloat;
				dataSet[j].numInt = dataSet[j-1].numInt;
				strcpy(dataSet[j].color, dataSet[j-1].color);
				
				strcpy(dataSet[j-1].item, tempA);
				dataSet[j-1].numFloat = tempB;
				dataSet[j-1].numInt = tempC;
				strcpy(dataSet[j-1].color, tempD);
				
				j--;
			}
		}
	}
	else
	{
		for (i=1; i<size; i++)
		{
			j=i;;
			while (j>0 && dataSet[j-1].numInt > dataSet[j].numInt)
			{
				strcpy(tempA, dataSet[j].item);
				tempB = dataSet[j].numFloat;
				tempC = dataSet[j].numInt;
				strcpy(tempD, dataSet[j].color);
				
				strcpy(dataSet[j].item, dataSet[j-1].item);
				dataSet[j].numFloat = dataSet[j-1].numFloat;
				dataSet[j].numInt = dataSet[j-1].numInt;
				strcpy(dataSet[j].color, dataSet[j-1].color);
				
				strcpy(dataSet[j-1].item, tempA);
				dataSet[j-1].numFloat = tempB;
				dataSet[j-1].numInt = tempC;
				strcpy(dataSet[j-1].color, tempD);
				
				j--;
			}
		}
	}
}

void sortByFloat(int size, int selection)
{
	printf("selection is %d\n", selection);
	int i, j;
	char tempA[20], tempD[20];
	char operator;
	float tempB;
	int tempC;
	if (selection == 1)
	{
		for (i=1; i<size; i++)
		{
			j=i;;
			while (j>0 && dataSet[j-1].numFloat < dataSet[j].numFloat)
			{
				strcpy(tempA, dataSet[j].item);
				tempB = dataSet[j].numFloat;
				tempC = dataSet[j].numInt;
				strcpy(tempD, dataSet[j].color);
				
				strcpy(dataSet[j].item, dataSet[j-1].item);
				dataSet[j].numFloat = dataSet[j-1].numFloat;
				dataSet[j].numInt = dataSet[j-1].numInt;
				strcpy(dataSet[j].color, dataSet[j-1].color);
				
				strcpy(dataSet[j-1].item, tempA);
				dataSet[j-1].numFloat = tempB;
				dataSet[j-1].numInt = tempC;
				strcpy(dataSet[j-1].color, tempD);
				
				j--;
			}
		}
	}
	else
	{
		for (i=1; i<size; i++)
		{
			j=i;;
			while (j>0 && dataSet[j-1].numFloat > dataSet[j].numFloat)
			{
				strcpy(tempA, dataSet[j].item);
				tempB = dataSet[j].numFloat;
				tempC = dataSet[j].numInt;
				strcpy(tempD, dataSet[j].color);
				
				strcpy(dataSet[j].item, dataSet[j-1].item);
				dataSet[j].numFloat = dataSet[j-1].numFloat;
				dataSet[j].numInt = dataSet[j-1].numInt;
				strcpy(dataSet[j].color, dataSet[j-1].color);
				
				strcpy(dataSet[j-1].item, tempA);
				dataSet[j-1].numFloat = tempB;
				dataSet[j-1].numInt = tempC;
				strcpy(dataSet[j-1].color, tempD);
				
				j--;
			}
		}
	}
}

