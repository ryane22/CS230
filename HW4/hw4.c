/****************************/
/**Ryan Evenstad Homework 2**/
/****************************/

#include "hw4.h"

int main()
{
	char selection[1];
	int i, dataSize;
	while(1)
	{
		printf("\n1. Sort data by the float value & print high to low\n");
		printf("2. Sort data by the float value & print low to high\n");
		printf("3. Sort data by the int value & print high to low\n");
		printf("4. Sort data by the int value & print low to high\n");
		printf("5. Exit\n");
		scanf("%s", selection);
		i = atoi(selection);
		if (i==1)
		{
			dataSize = copyToArray();
			sortByFloat(dataSize, i);
			printData(dataSize);
		}
		else if (i==2)
		{
			copyToArray();
			sortByFloat(dataSize, i);
			printData(dataSize);
		}
		else if (i==3)
		{
			copyToArray();
			sortByInt(dataSize, i);
			printData(dataSize);
		}
		else if (i==4)
		{
			copyToArray();
			sortByInt(dataSize, i);
			printData(dataSize);
		}
		else if (i==5)
		{
			break;
		}
		else
		{
			printf("Invalid selection (1-5)");
		}
	}
	return 0;
}