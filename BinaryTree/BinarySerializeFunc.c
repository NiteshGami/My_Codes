#include "BinaryTreeHeader.h"

void serializeTree (TNode *root, FILE *fp)
{
	if (NULL == root) {
		if(stdout != fp)
			fprintf(fp, "%d\n", -1);
		return;
	}
	fprintf(fp, "%d\n", root->data);
	serializeTree(root->left, fp);
	serializeTree(root->right, fp);
}

void deserializeTree (TNode **root, FILE *fp)
{
	printf("Enter");
	int data = -1;
	if (NULL == root)
		return;
	
	if (EOF == fscanf(fp, "%d", &data)) {
		printf("EOF :%d", data);
		return;
	}

	printf("%d\n", data);
	
	if (data == -1) {
		*root = NULL;
		return;
	}

	*root = newNode(data);
	deserializeTree(&((*root)->left), fp);
	deserializeTree(&((*root)->right), fp);
}
