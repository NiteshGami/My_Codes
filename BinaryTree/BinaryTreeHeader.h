#ifndef BINARYTREEHEADER_H
#define BINARYTREEHEADER_H
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} TNode;

TNode* newNode (int data);

#ifdef SERIALIZETREE
void serializeTree (TNode *root, FILE *fp);
void deserializeTree (TNode **root, FILE *fp);
#endif
#endif
