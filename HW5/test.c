/****************************/
/**Ryan Evenstad Homework 2**/
/****************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//global variable
char itemArray[400][100];
struct data
{
	char item[20];
	float numFloat;
	int numInt;
	char color[20];
};
struct data *dataSet;

void printData(int size)
{
	int i;
	for (i=0; i<size; i++)
	{
		printf("%s %f %d %s\n", dataSet[i].item, dataSet[i].numFloat, dataSet[i].numInt, dataSet[i].color);
	}
}

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

void copyItemArrayToStructArray(int numItems)
{
	int count=0, i=0;
	dataSet = (struct data*)calloc(100, sizeof(struct data));
	
	while(count < numItems)
	{
		strcpy(dataSet[i].item, itemArray[count]);
		count++;
		dataSet[i].numFloat = atof(itemArray[count]);;
		count++;
		dataSet[i].numInt = atoi(itemArray[count]);
		count++;
		strcpy(dataSet[i].color, itemArray[count]);
		count++;
		i++;
	}
	free(dataSet);
}

int copyToArray(void)
{
	int itemNum=0;
	int length;
	char line[100];
	char *lineItem;
	FILE *dataFile;
	dataFile = fopen("hw4.data", "rt");//hard coded data file
	
	while (fgets(line, 100, dataFile) != NULL)//while not end of file
	{
		length = strlen(line);
		if (line[length-1] == '\n')
		{
			line[length-1] = 0;
		}
		lineItem = strtok(line, " ");
		while (lineItem!=NULL)
		{
			strcpy(itemArray[itemNum], lineItem);
			itemNum++;
			lineItem = strtok(NULL, " ");
		}
	}
	fclose(dataFile);
	copyItemArrayToStructArray(itemNum);
	return itemNum/4;
}

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