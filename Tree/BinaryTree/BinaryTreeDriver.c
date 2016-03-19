#include "BinaryTreeHeader.h"

TNode* newNode (int data)
{
	TNode *temp = (TNode *)calloc(1, sizeof(TNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;	
	return temp;
}


int main()
{
	TNode *root = newNode(10);
	root->left = newNode(15);
	root->right = newNode(20);
	root->left->left = newNode(25);
	root->left->left->left = newNode(30);

#ifdef SERIALIZETREE
	TNode *newRoot = NULL;
	FILE *fp = fopen("./serializeTree.txt","w");
	if(NULL == fp)
	{
		printf("fopen error write mode...return");
		return -1;
	}
	serializeTree(root, fp);
	fclose(fp);

	fp = fopen("./serializeTree.txt","r");
	if(NULL == fp)
	{
		printf("fopen error read mode...return");
		return -1;
	}
	deserializeTree(&newRoot, fp);
	fclose(fp);
	
	serializeTree(newRoot, stdout);
#endif
	return 0;
}

