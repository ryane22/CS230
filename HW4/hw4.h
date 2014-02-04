/****************************/
/**Ryan Evenstad Homework 2**/
/****************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char itemArray[400][100];
struct data
{
	char item[20];
	float numFloat;
	int numInt;
	char color[20];
};
struct data *dataSet;