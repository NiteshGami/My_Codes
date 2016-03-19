#include "HeapHeader.h"


static void __heapify (THeap *heap, int index) ;
static void __swap(int *fNode, int *sNode);


int getTop (THeap *heap) {
	if(!heap) {
		printf("No Heap Exists...");
		return -1;
	}
	if (heap->curHeapSize > 0) {
		return heap->heapArray[0];
	} else {
		return -1;
	}
}
int comparatorMin (int fArgs, int sArgs)
{
	return (fArgs < sArgs);
}

int comparatorMax (int fArgs, int sArgs)
{
	return (fArgs > sArgs);
}
void createHeap (THeap **heap, int MaxHeapSize, int (*comparator)(int, int))
{
	if (!heap) {
		printf("heap is null...return");
		return;
	}

	if(!comparator) {
		printf("comparator func is null...");
		return;
	}

	*heap = (THeap *)calloc(1, sizeof(THeap));
	if(!*heap) {
		printf("Malloc Error..return");
		return;
	}

	(*heap)->curHeapSize = 0;
	(*heap)->MaxHeapSize = MaxHeapSize;
	(*heap)->comparatorFunc = comparator;	
	
	(*heap)->heapArray = (int *)calloc(MaxHeapSize, sizeof(int));
	if(!((*heap)->heapArray)) {
		printf("HeapArray Malloc Error");
		free(*heap);
		*heap = NULL;
		return;
	}
	return;
}

void deleteHeap (THeap **heap)
{
	if (heap) {
		if(*heap) {
			if((*heap)->heapArray) {
				free((*heap)->heapArray);
				(*heap)->heapArray = NULL;
			}
			free(*heap);
			*heap = NULL;
		}
	}
}

void insertHeap (THeap *heap, int key)
{
	int iCurrent = 0, iParent=0;
	if (heap->curHeapSize >= heap->MaxHeapSize) {
		printf("Heap is Full...can't insert");
		return;
	}
	
	heap->heapArray[heap->curHeapSize] = key;
	heap->curHeapSize++;

	iCurrent = heap->curHeapSize-1;
	iParent = (iCurrent-1)/2;
	while ( iParent >= 0) {
		if(heap->comparatorFunc(heap->heapArray[iCurrent], heap->heapArray[iParent]))
		{
			__swap(&(heap->heapArray[iParent]), &(heap->heapArray[iCurrent]));
			iCurrent = iParent;
			iParent = (iCurrent-1)/2;
		} else {
			break;
		}
	}	
}

static void __swap(int *fNode, int *sNode)
{
	int temp = *fNode;
	*fNode = *sNode;
	*sNode = temp;
}

static void __heapify (THeap *heap, int index) 
{
	
	if(index >= heap->curHeapSize) {
		printf("wrong index");
		return;
	}
	int minMaxIndex = index;
	int leftChild = 2*index + 1;
	int rightChild = 2*index + 2;

	if (leftChild < heap->curHeapSize) {
		if (heap->comparatorFunc(heap->heapArray[leftChild], heap->heapArray[minMaxIndex]))
			minMaxIndex = leftChild;
	}

	if (rightChild < heap->curHeapSize) {
		if (heap->comparatorFunc(heap->heapArray[rightChild], heap->heapArray[minMaxIndex]))
			minMaxIndex = rightChild;
	}

	if (minMaxIndex != index) {
		__swap(&(heap->heapArray[index]), &(heap->heapArray[minMaxIndex]));
		__heapify(heap, minMaxIndex);
	}		
}

int extractTop (THeap *heap)
{
	int temp = -1;
	if (heap->curHeapSize > 0) {
		temp = heap->heapArray[0];
		heap->curHeapSize--;
		heap->heapArray[0] = heap->heapArray[heap->curHeapSize];
		__heapify(heap, 0);
	}
	return temp;
}

void printHeap (THeap *heap)
{
	int i = 0;
	for( i = 0; i < heap->curHeapSize; i++)
		printf("%d,",heap->heapArray[i]);
	printf("\n");
}
