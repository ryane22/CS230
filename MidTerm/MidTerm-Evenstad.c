/************************/
/*Ryan Evenstad Mid-Term*/
/************************/

#include <stdio.h>
#include <stdlib.h>

struct journalData
{
	char author[42];
	char key1[42];
	char key2[42];
	char key3[42];
	char publisher[42];
	char date[42];
};
struct journalData *journal;

struct confData
{
	char author[42];
	char keyword[42];
	char sponsor[42];
	char date[42];
	char location[42];
};
struct confData *conf;

void main(void)
{
	int jcount=0, ccount=0, i=0, c=0, j=0;
	char cur[42];
	FILE *dataFile;
	dataFile = fopen("midterm.data", "r");
	if (dataFile == NULL)
	{
		printf("cannot open file\n");
		exit(1);
	}
	while(fscanf(dataFile, "%s", cur) != EOF)
	{
		if(!strcmp("journal", cur))
			jcount++;
		else if(!strcmp("Journal", cur))
			jcount++;
		else if(!strcmp("conference", cur))
			ccount++;
		else if(!strcmp("Conference", cur))
			ccount++;
	}
	
	rewind(dataFile);
	journal = (struct journalData*)calloc(jcount, sizeof(struct journalData));
	conf = (struct confData*)calloc(ccount, sizeof(struct confData));
	
	while(fscanf(dataFile, "%s", cur) != EOF)
	{
		if(!strcmp("journal", cur) || !strcmp("Journal", cur))
		{
			fscanf(dataFile, "%s", journal[j].author);
			fscanf(dataFile, "%s", journal[j].key1);
			fscanf(dataFile, "%s", journal[j].key2);
			fscanf(dataFile, "%s", journal[j].key3);
			fscanf(dataFile, "%s", journal[j].publisher);
			fscanf(dataFile, "%s", journal[j].date);
			j++;
		}
		else if(!strcmp("conference", cur) || !strcmp("Conference", cur))
		{
			fscanf(dataFile, "%s", conf[c].author);
			fscanf(dataFile, "%s", conf[c].keyword);
			fscanf(dataFile, "%s", conf[c].sponsor);
			fscanf(dataFile, "%s", conf[c].date);
			fscanf(dataFile, "%s", conf[c].location);
			c++;
		}
	}
	fclose(dataFile);
	
	for(i=jcount-1; i>=0; i--)
	{
		printf("%s ", journal[i].author);
		printf("%s ", journal[i].key1);
		printf("%s ", journal[i].key2);
		printf("%s ", journal[i].key3);
		printf("%s ", journal[i].publisher);
		printf("%s\n", journal[i].date);
	}
	
	for(i=ccount-1; i>=0; i--)
	{
		printf("%s ", conf[i].author);
		printf("%s ", conf[i].keyword);
		printf("%s ", conf[i].sponsor);
		printf("%s ", conf[i].date);
		printf("%s\n", conf[i].location);
	}
}