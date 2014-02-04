/***********************/
/* Ryan Evenstad Final */
/***********************/

#include <stdio.h>
#include <stdlib.h>

struct treeNode{
	char name;
	int value;
	struct treeNode *left;
	struct treeNode *right;
};

find(int target, struct treeNode *node)
{
	if(target <= node->value)
	{
		if(node->value == 999)
		{
			printf("%c\n", node->name);
		}
		else
		{
			printf("%c\n", node->name);
			find(target, node->left);
		}
	}
	else
	{
		if(node->value == 999)
		{
			printf("%c\n", node->name);
		}
		else
		{
			printf("%c\n", node->name);
			find(target, node->right);
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc>1)
	{
		struct treeNode *Root = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *Left = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *Right = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *L_Left = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *L_Right = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *R_Left = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *R_Right = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *L_L_Left = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *L_L_Right = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *L_R_Left = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *L_R_Right = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *R_L_Left = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *R_L_Right = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *R_R_Left = (struct treeNode *)malloc(sizeof(struct treeNode));
		struct treeNode *R_R_Right = (struct treeNode *)malloc(sizeof(struct treeNode));
	
		Root->name = 'A';
		Root->value = 4;
		Root->left = Left;
		Root->right = Right;
	
		Left->name = 'B';
		Left->value = 2;
		Left->left = L_Left;
		Left->right = L_Right;
	
		Right->name = 'C';
		Right->value = 6;
		Right->left = R_Left;
		Right->right = R_Right;
	
		L_Left->name = 'D';
		L_Left->value = 1;
		L_Left->left = L_L_Left;
		L_Left->right = L_L_Right;
	
		L_Right->name = 'E';
		L_Right->value = 3;
		L_Right->left = L_R_Left;
		L_Right->right = L_R_Right;
	
		R_Left->name = 'F';
		R_Left->value = 5;
		R_Left->left = R_L_Left;
		R_Left->right = R_L_Right;
	
		R_Right->name = 'G';
		R_Right->value = 7;
		R_Right->left = R_R_Left;
		R_Right->right = R_R_Right;
		
		L_L_Left->name = '1';
		L_L_Left->value = 999;
		L_L_Left->left = NULL;
		L_L_Left->right = NULL;
	
		L_L_Right->name = '2';
		L_L_Right->value = 999;
		L_L_Right->left = NULL;
		L_L_Right->right = NULL;
	
		L_R_Left->name = '3';
		L_R_Left->value = 999;
		L_R_Left->left = NULL;
		L_R_Left->right = NULL;
	
		L_R_Right->name = '4';
		L_R_Right->value = 999;
		L_R_Right->left = NULL;
		L_R_Right->right = NULL;
	
		R_L_Left->name = '5';
		R_L_Left->value = 999;
		R_L_Left->left = NULL;
		R_L_Left->right = NULL;
	
		R_L_Right->name = '6';
		R_L_Right->value = 999;
		R_L_Right->left = NULL;
		R_L_Right->right = NULL;
	
		R_R_Left->name = '7';
		R_R_Left->value = 999;
		R_R_Left->left = NULL;
		R_R_Left->right = NULL;
	
		R_R_Right->name = '8';
		R_R_Right->value = 999;
		R_R_Right->left = NULL;
		R_R_Right->right = NULL;
		//printf("there was a command line argument\n");
		
		find(atoi(argv[1]), Root);
	}
	else
		printf("please enter a commanand line argument next time\n");
	
	return 1;
}