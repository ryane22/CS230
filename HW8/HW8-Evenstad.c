/**************************/
/*Ryan Evenstad Homework 8*/
/**************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct doubleLink
{
	char name[42];
	struct doubleLink *next;
	struct doubleLink *prev;
};
struct doubleLink *head, *tail;

void printForwardList(void)
{
	printf("\nNon-Decreasing Order (from head)\n\n");
	struct doubleLink *temp = head;
	while(temp != NULL)
	{
		printf("%s\n", temp -> name);
		temp = temp -> next;
	}
}

void printBackwardList(void)
{
	printf("\n\nNon-Increasing Order (from tail)\n\n");
	struct doubleLink *temp =tail;
	while(temp != NULL)
	{
		printf("%s\n", temp -> name);
		temp = temp -> prev;
	}
}

void insert(char iname[42])
{
	//printf("IN INSERT\n");
	struct doubleLink *current = (struct doubleLink *)malloc(sizeof(struct doubleLink));
	strcpy(current -> name, iname);
	if(head == NULL) //linked list is empty
	{
		head = tail = current;
		current -> next = current -> prev = NULL;
	}
	else
	{
		struct doubleLink *temp = head;
		while(temp != NULL)
		{
			if(strcmp(current -> name, temp -> name) <= 0)
			{
				if(temp == head) //insert to head
				{
					current -> next = head;
					current -> prev = NULL;
					head -> prev = current;
					head = current;
					break;
				}
				else //insert into linked list not at head or tail
				{
					current -> prev = temp -> prev;
					temp -> prev -> next = current;
					temp -> prev = current;
					current -> next = temp;
					break;
				}
			}
			if(temp == tail) //insert to tail
			{
				tail -> next = current;
				current -> prev = tail;
				tail = current;
				break;
			}
			else
				temp = temp -> next;
		}
	}
}

void delete(char dname[42])
{
	int check = 1;
	struct doubleLink *temp = head;
	while(temp != NULL)
	{
		if(!strcmp(temp -> name, dname))
		{
			if(temp == head) //delete the head
			{
				head = head -> next;
				head -> prev = NULL;
			}
			else if(temp == tail) //delete the tail
			{
				tail = tail -> prev;
				tail -> next = NULL;
			}
			else //delete non head or tail node
			{
				temp -> prev -> next = temp -> next;
				temp -> next -> prev = temp -> prev;
			}
			check = 0;
			free(temp);
			break;
		}
		temp = temp -> next;
	}
	if(check) printf("Tried to delete %s, but could it could not be found\n");
}

int main(void)
{
	head = NULL;
	tail = NULL;
	char fname[42];
	char opCode[2];
	char fileName[100];
	
	printf("Enter data file: ");
	scanf("%s", fileName);
	
	FILE *dataFile;
	dataFile = fopen(fileName, "r");
	if (dataFile == NULL)
	{
		printf("cannot open file\n");
		exit(1);
	}
	while(fscanf(dataFile, "%s %s", fname, opCode) != EOF)
	{
		if(!strcmp(opCode, "a"))
		{
			insert(fname);
		}
		else if(!strcmp(opCode, "d"))
		{
			delete(fname);
		}
	}
	printForwardList();
	printBackwardList();
}