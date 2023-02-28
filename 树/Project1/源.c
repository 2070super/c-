#include<stdio.h>
typedef char DATA;
typedef struct treenode
{
	DATA data;
	struct treenode* left;
	struct treenode* right;
}BT;
void Preorder(BT* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	printf("%c", root->data);
	Preorder(root->left);
	Preorder(root->right);		
}
void Midorder(BT* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	Preorder(root->left);
	printf("%c", root->data);
	Preorder(root->right);
}
void Treesize(BT* root, int* psize)
{
	if (root == NULL)
		return;
	else
	{
		(*psize)++;
	}
	Treesize(root->left, psize);
	Treesize(root->right, psize);
}
int Treesize1(BT* root)
{
	if (root = NULL)
		return 0;
	else
		return 1 + Treesize1(root->left) + Treesize1(root->right);
}
BT* Createnode(int x)
{
	BT* node = (BT*)malloc(sizeof(BT));
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
