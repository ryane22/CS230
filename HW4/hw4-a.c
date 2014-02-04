/****************************/
/**Ryan Evenstad Homework 2**/
/****************************/

#include "hw4-a.h"

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