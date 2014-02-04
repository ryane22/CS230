/****************************/
/**Ryan Evenstad Homework 5**/
/****************************/

#include <stdlib.h>
#include <stdio.h>
//global
int top = -1;
int lineCount = 0;

int push(int stack[200])
{
	if ((top+1) >= 200) 
	{
		printf("Stack Overflow\n");
	}
	else
	{
		top++;
		stack[top] = 1;
	}
	return stack[200];
}

int pop(int stack[200])
{
	//this exits the program the first time there is an unmatched } in the stack
	if (top == -1)
	{
		printf("There is an unmatched }\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		top--;
		stack[top+1] = 0;
	}
}

void main (void)
{
	int stack[200];
	char fileName[100];
	char line[200];
	int c, i;
	char item;
	//set all stack elements to zero
	for(i = 0; i < 200; i++)
	{
		stack[i] = 0;
	}
	
	printf("Enter data file: ");
	scanf("%s", fileName);
	
	FILE *dataFile;
	dataFile = fopen(fileName, "r");
	if (dataFile == NULL)
	{
		printf("cannot open file\n");
		exit(EXIT_FAILURE);
	}
	while ((c = fgetc(dataFile)) != EOF)
	{
		if (c == '{') 
		{
			stack[200] = push(stack);
		}
		else if (c == '}')
		{
			stack[200] = pop(stack);
		}
		else if (c == '\n')
		{
			lineCount++;
		}
	}
	
	if (top == -1)
	{
		printf("There are equal numbers of curly brackets!\n");
	}
	else if (top > -1)
	{
		printf("There are too many {\n");
	}
	
	fclose(dataFile);
}