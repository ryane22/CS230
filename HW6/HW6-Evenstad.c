/****************************/
/**Ryan Evenstad Homework 6**/
/****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
	char word[50];
	int wc;
};
struct data *cloud;

void sort(struct data *cloud, int count)
{
	int array[count];
	int position = 0;
	int boolean = 1; //boolean zero means i is not in j
	int i, j, k;
	
	for(i=0; i<=count; i++) //set all array elements to -1
		array[i] = 0;
	
	array[position] = 0;
	position++;
	for(i=1; i<count; i++)
	{
		for(j=0; j<=position; j++)
		{
			boolean = 1;
			if(!strcmp(cloud[i].word, cloud[array[j]].word))
			{
				break;
			}
			else boolean = 0;
		}
		if(boolean == 0)
		{
			array[position] = i;
			position++;
		}
	}

//from here prints the 10 highest values
	printf("\nWORD           COUNT\n\n");
	int countArray[position];
	int countPosition = 0;
	int newHigh = 0, oldHigh = 1000000, n = 0;
	for(i=0; i<=position; i++)
	{
		newHigh = 0;
		for (j=0; j<=position; j++)
		{
			//find the highest wc
			if((cloud[array[j]].wc > newHigh) && (cloud[array[j]].wc < oldHigh))
			{
				newHigh = cloud[array[j]].wc;
				countArray[countPosition] = newHigh;
			}
		}
		oldHigh = newHigh;
		countPosition++;
	}
	for(i=0; i<countPosition; i++)
	{
		for(j=i; j<=position; j++)
		{
			if(cloud[array[j]].wc < countArray[i])
				continue;
			if(cloud[array[j]].wc == countArray[i])
			{
				printf("%-15s %d\n", cloud[array[j]].word, cloud[array[j]].wc);
				n++;
			}
		}
		if(n == 10) break;
	}
	printf("\n");
}

void density(struct data *cloud, int count)
{
	int i,j,k;
	for (k = 0; k<count; k++)
	{
		cloud[k].wc = 1;
	}
	for(i = 0; i<count; i++)
	{
		for(j = i+1; j<count; j++)
		{
			if (!strcmp(cloud[i].word, cloud[j].word))
			{
				cloud[i].wc++;
				cloud[j].wc++;
			}
		}
	}
}

void format(struct data *cloud, int count)
{
	int i, j, k;
	for(i = 0; i<count; i++)
	{
		for (j = 0; cloud[i].word[j] != '\0'; j++)
		{
			if (cloud[i].word[j] == '\'')
			{
				continue;
			}
			else if (cloud[i].word[j] == '(')
			{
				for(k = 0; cloud[i].word[k] != '\0'; k++)
				{
					cloud[i].word[k] = cloud[i].word[k+1];
				}
			}
			else if (isspace(cloud[i].word[j]))
			{
				cloud[i].word[j] = '\0';
			}
			else if (ispunct(cloud[i].word[j]))
			{
				cloud[i].word[j] = ' ';//want to delete this character
			}
			else
			{
				cloud[i].word[j] = (char)tolower(cloud[i].word[j]);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	int i = 0;
	int numWords = 0;
	char cur[50];
	//check if argv[1] is a valid filename
	FILE *dataFile;
	dataFile = fopen(argv[1], "r");
	if (dataFile == NULL)
	{
		printf("cannot open file\n");
		exit(1);
	}
	//get number of lines in file
	while(fscanf(dataFile, "%s", cur) != EOF)
	{
		numWords++;
	}
	rewind(dataFile);
	
	cloud = (struct data*)calloc(numWords, sizeof(struct data));
	//put words in file into struct
	while(fscanf(dataFile, "%s", cloud[i].word) != EOF)
	{
		i++;
	}
	
	format(cloud, numWords);
	format(cloud, numWords);
	density(cloud, numWords);
	sort(cloud, numWords);
	
	free(cloud);
	fclose(dataFile);
	return 0;
}