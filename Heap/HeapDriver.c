#include "HeapHeader.h"

int main() {
#if 1
	THeap *heap = NULL;
	createHeap(&heap, 5, comparatorMax);
	insertHeap(heap, 5);
	printHeap(heap);
	insertHeap(heap, 7);
	printHeap(heap);
	insertHeap(heap, 3);
	printHeap(heap);	
	insertHeap(heap, 1);
	printHeap(heap);
	insertHeap(heap, 6);
	printHeap(heap);
	insertHeap(heap, 8);
	printHeap(heap);
	printf("************** %d\n", extractTop(heap));
	printHeap(heap);
	printf("************** %d\n", extractTop(heap));
	printHeap(heap);
	printf("************** %d\n", extractTop(heap));
	printHeap(heap);
	printf("************** %d\n", extractTop(heap));
	printHeap(heap);
	printf("************** %d\n", extractTop(heap));
	printHeap(heap);
	printf("************** %d\n", extractTop(heap));
	printHeap(heap);
#endif
#if 0
	THeap *MinHeap = NULL;
	THeap *MaxHeap = NULL;
	createHeap(&MinHeap, 100, comparatorMin);
	createHeap(&MaxHeap, 100, comparatorMax);
	
	int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	int size = sizeof(A) / sizeof(A[0]);
	int i =0;
	for( i = 0; i < size; i++)
	{
		printf("CurMedian: %d\n",findMedian(MaxHeap, MinHeap, A[i]));
		printHeap(MaxHeap);
		printHeap(MinHeap);
	}
	return 0;
#endif

}
