/***************************/
/*Ryan Evenstad Homework 11*/
/***************************/

#include "HW11.h"
//#include <time.h> //used for the delay

/*long int globalCost;
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
typedef struct doubleLink link;*/

void freeStuff(void)
{
	struct doubleLink *temp = head;
	while(temp -> next != NULL)
	{
		temp = temp -> next;
		free(head->self);
		free(head);
		head = temp;
	}
}

/*// used for testing
void printAll(void)
{
	int i;
	printf("\nALL\n\n");
	struct doubleLink *temp = head;
	while(temp != NULL)
	{
		printf("%s\n", temp -> name);
		for(i=0; i<10; i++)
		{
			printf("\t%15s %d\n", temp->self->destList[i], temp->self->costList[i]);
		}
		temp = temp -> next;
	}
}*/

/* not used
void printForwardList(void)
{
	printf("\nNon-Decreasing Order (from head)\n\n");
	struct doubleLink *temp = head;
	while(temp != NULL)
	{
		printf("%s\n", temp -> name);
		temp = temp -> next;
	}
}*/

/* not used
void printBackwardList(void)
{
	printf("\n\nNon-Increasing Order (from tail)\n\n");
	struct doubleLink *temp = tail;
	while(temp != NULL)
	{
		printf("%s\n", temp -> name);
		temp = temp -> prev;
	}
}*/

void createLinks(char cname[84], char dest[84], int cost)
{
	int i;
	struct doubleLink *current = head;
	while(current != NULL)
	{
		if(!strcmp(current->name, cname))
		{
			for(i=0; i<10; i++)
			{
				if(!strcmp(current->self->destList[i], ""))
				{
					strcpy(current->self->destList[i], dest);
					//printf("%s\n", current->self->destList[i]);
					current->self->costList[i] = cost;
					break;
				}
			}
		}
		current = current -> next;
	}
}

void insert(char iname[84])
{
	struct doubleLink *current = (struct doubleLink *)malloc(sizeof(struct doubleLink));
	struct destLink *dest = (struct destLink *)malloc(sizeof(struct destLink));
	int i;
	for(i=0; i<10; i++)
	{
		dest->costList[i] = 1000000000;
	}
	current -> self = dest;
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

/* not used in this program
void delete(char dname[84])
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
}*/

int main(int argc, char *argv[])
{
	globalCost = 0;
	numWalks = 0;
	
	//curtime = time(NULL);
	//srand(curtime);
	srand(12212012);
	
	head = NULL;
	tail = NULL;
	char fname[84];
	char dest[84];
	char fileName[100];
	char start[84];
	int fcost;
	
	printf("Enter data file: ");
	scanf("%s", fileName);
	
	FILE *dataFile;
	dataFile = fopen(fileName, "r");
	if (dataFile == NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	while(fscanf(dataFile, "%s", fname) != EOF)
	{
		if(!strcmp(fname, "STOP"))
		{
			break;
		}
		else
		{
			insert(fname);
		}
	}
	while(fscanf(dataFile, "%s %s %d", fname, dest, &fcost) != EOF)
	{
		if(!strcmp(fname, "STOP"))
		{
			break;
		}
		else
		{
			createLinks(fname, dest, fcost);
		}
	}
	fscanf(dataFile, "%s", start);
	int x;
	if(argc>1)
	{
		void *handle;
		handle = dlopen("HW11-lib-Evenstad.so", RTLD_LAZY);
		if(!handle) printf("handle error");
		switch(atoi(argv[1]))
		{
			case 0:
				printf("\nDrunkard's Walk\n");
				int (*drunk)(char*);
				drunk = dlsym(handle, "drunkWalk");
				if(dlsym == NULL) printf("dlsym error %s", dlerror);
				x = (*drunk)(start);
				//x = drunkWalk(start);
				break;
			case 1:
				printf("\nGreedy Walk\n");
				int (*greed)(char*);
				greed = dlsym(handle, "greedy");
				if(dlsym == NULL) printf("dlsym error %s", dlerror);
				x = (*greed)(start);
				//x = greedy(start);
				break;
			case 2:
				printf("\nGenerous Walk\n");
				int (*gener)(char*);
				gener = dlsym(handle, "generous");
				if(dlsym == NULL) printf("dlsym error %s", dlerror);
				x = (*gener)(start);
				//x = generous(start);
				break;
			default:
				printf("\nNon-applicable argument\n0-Drunkard's Walk\n1-Greedy Walk\n2-Generous Walk\n");
				break;
		}
		dlclose(handle);
	}
	else
	{
		printf("Need command line argument\n");
	}
	//printForwardList();
	//printBackwardList();
	//printAll();
	if(x!=0)
	{
		printf("\nYou started at %s\nYou're home and it only cost you %d!\n\n", start, globalCost);
	}
	else
	{
		printf("Please try again\n\n");
	}
	fclose(dataFile);
	freeStuff();
}
