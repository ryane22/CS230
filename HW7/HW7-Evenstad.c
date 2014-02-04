/**************************/
/*Ryan Evenstad Homework 7*/
/**************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define null 666

struct directory
{
	char circle[42];
	int startBlock;
};
struct directory *dict;

struct fileSystem
{
	char id[42];
	char number[8];
	int prev;
	int next;
};
struct fileSystem *FAT;

void print(void)
{
	int i, current;
	printf("\nDIRECTORY\n");
	printf("Index Circle     StartBlock\n");
	for(i=0; i<10; i++)
	{
		if(strcmp(dict[i].circle, ""))
			printf("%-5d %-10s %10d\n", i, dict[i].circle, dict[i].startBlock);
	}
	printf("\nFAT\n");
	printf("Index Name       Number     Prev Next\n");
	for(i=0; i<100; i++)
	{
		if(strcmp(FAT[i].id, ""))
			printf("%-5d %-10s %-10s %4d %4d\n", i, FAT[i].id, FAT[i].number, FAT[i].prev, FAT[i].next);
	}
}

int addToFat(char name[42], char num[8], int last)
{
	int i;
	for(i=0; i<100; i++)
	{
		if(!strcmp(FAT[i].id, ""))
		{
			strcpy(FAT[i].id, name);
			strcpy(FAT[i].number, num);
			FAT[i].prev = last;
			FAT[i].next = null;
			break;
		}
	}
	return i;
}

int addNewToFat(char name[42], char num[8], int dictPlace)
{
	int i;
	for(i=0; i<100; i++)
	{
		if(!strcmp(FAT[i].id, ""))
		{
			strcpy(FAT[i].id, name);
			strcpy(FAT[i].number, num);
			FAT[i].prev = (1000 + dictPlace);
			FAT[i].next = null;
			//printf("BLANK IN FAT\n");
			break;
		}
	}
	return i;
}

void addEndToFat(char name[42], char num[8], int start)
{
	//printf("IN ADDENDTOFAT\n");
	int current = start, last;
	while(current != null)
	{
		//printf("IN WHILE\n");
		last = current;
		current = FAT[current].next;
	}
	FAT[last].next = addToFat(name, num, last);
	

}

void add(char circ[42], char name[42], char num[8])
{
	int i;
	//printf("%s %s %s ", circle, name, num);
	//printf("IN ADD\n");
	for(i=0; i<10; i++)
	{
		if(!strcmp(dict[i].circle, circ))
		{
			//go through linked list add to end
			addEndToFat(name, num, dict[i].startBlock);
			//printf("IN CIRCLE\n");
			break;
		}
		else if(!strcmp(dict[i].circle, ""))
		{
			strcpy(dict[i].circle, circ);
			dict[i].startBlock = addNewToFat(name, num, i);
			break;
		}
	}
}

void delete(char circ[42], char name[42])
{
	int i, current, last, after;
	for(i=0; i<100; i++)
	{
		if(!strcmp(dict[i].circle, circ))
		{
			current = dict[i].startBlock;
			last = FAT[current].prev;
			while(current != null)
			{
				if(!strcmp(FAT[current].id, name))
				{
					if(current == dict[i].startBlock)
					{
						//node is first in list, remove it and the directory entry
						after = FAT[current].next;
						dict[i].startBlock = FAT[current].next;
						FAT[after].prev = FAT[current].prev;
						strcpy(FAT[current].id, "");
						strcpy(FAT[current].number, "");
						FAT[current].next = FAT[current].prev = 0;
						if(after == null)
						{
							strcpy(dict[i].circle, "");
							dict[i].startBlock = 0;
						}
					}
					else if(FAT[current].next == null)
					{
						//node is last in the list
						FAT[last].next = FAT[current].next;
						strcpy(FAT[current].id, "");
						strcpy(FAT[current].number, "");
						FAT[current].next = FAT[current].prev = 0;
					}
					else
					{
						//node is not first or last in list
						after = FAT[current].next;
						FAT[last].next = FAT[current].next;
						FAT[after].prev = FAT[current].prev;
						strcpy(FAT[current].id, "");
						strcpy(FAT[current].number, "");
						FAT[current].next = FAT[current].prev = 0;
					}
					break;
				}
				last = current;
				current = FAT[current].next;
			}
			break;
		}
	}
}

void query(char name[42])
{
	int i, last, next;
	char circ[42];
	for(i=0; i<100; i++)
	{
		if(!strcmp(FAT[i].id, name))
		{
			printf("\nIn %s's Circle\n", name);
			next = FAT[i].next;
			while(next!=null)
			{
				printf("%-10s %d\n", FAT[next].id, FAT[next].number);
				next = FAT[next].next;
			}
			last = FAT[i].prev;
			while(last < 1000)
			{
				printf("%-10s %d\n", FAT[last].id, FAT[next].number);
				last = FAT[last].prev;
			}
			strcpy(circ, dict[last-1000].circle);
			
		}
	}
}

int main(void)
{
	char tempCircle[42];
	char tempName[42];
	char tempNum[8];
	char op[2];
	char fileName[100];
	dict = (struct directory*)calloc(10, sizeof(struct directory));
	FAT = (struct fileSystem*)calloc(100, sizeof(struct fileSystem));
	
	printf("Enter data file: ");
	scanf("%s", fileName);
	
	FILE *dataFile;
	dataFile = fopen(fileName, "r");
	if (dataFile == NULL)
	{
		printf("cannot open file\n");
		exit(1);
	}
	while(fscanf(dataFile, "%s", tempCircle) != EOF)
	{
		fscanf(dataFile, "%s", tempName);
		fscanf(dataFile, "%s", tempNum);
		fscanf(dataFile, "%s", op);
		if(!strcmp(op,"a"))
		{
			add(tempCircle, tempName, tempNum);
		}
		else if(!strcmp(op,"d"))
		{
			delete(tempCircle, tempName);
		}
		else if(!strcmp(op,"q"))
			query(tempName);
	}
	fclose(dataFile);
	print();
	return 1;
}