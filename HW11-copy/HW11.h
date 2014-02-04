/***************************/
/*Ryan Evenstad Homework 11*/
/***************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

long int globalCost;
int numWalks;
time_t curtime;

struct destLink
{
	char destList[10][84];
	int costList[10];
};

struct doubleLink
{
	char name[84];
	struct doubleLink *next;
	struct doubleLink *prev;
	struct destLink *self;
};
struct doubleLink *head, *tail;
typedef struct doubleLink link;
