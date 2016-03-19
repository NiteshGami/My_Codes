#ifndef HEAPHEADER_H
#define HEAPHEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct HeapNode
{
	int curHeapSize;
	int MaxHeapSize;
	int *heapArray;
	int (*comparatorFunc)(int fArgs, int sArgs);
} THeap;


void createHeap(THeap **heap, int MaxHeapSize, int (*comparator)(int , int ));
void deleteHeap (THeap **heap);
void insertHeap (THeap *heap, int key);
int extractTop (THeap *heap);
void printHeap (THeap *heap);
int comparatorMin (int fArgs, int sArgs);
int comparatorMax (int fArgs, int sArgs);
int getTop (THeap *heap);
int findMedian (THeap *MaxHeap, THeap *MinHeap, int newNum);
#endif
