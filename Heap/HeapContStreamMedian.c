#include "HeapHeader.h"

int findMedian (THeap *MaxHeap, THeap *MinHeap, int newNum)
{
	int curMedian = -1;	
	if (MaxHeap->curHeapSize == MinHeap->curHeapSize) {
		
		if (newNum < getTop(MaxHeap)) {
			insertHeap(MaxHeap, newNum);
			curMedian = getTop(MaxHeap);
		} else {
			insertHeap(MinHeap, newNum);
			curMedian = getTop(MinHeap);
		}
	
	 } else if (MaxHeap->curHeapSize > MinHeap->curHeapSize) {
			
		if (newNum < getTop(MaxHeap)) {
			insertHeap(MinHeap, extractTop(MaxHeap));
			insertHeap(MaxHeap, newNum);
		} else {
			insertHeap(MinHeap, newNum);
		}
		curMedian = (getTop(MaxHeap) + getTop(MinHeap))/2;
		
	 }  else {
		if (newNum < getTop(MaxHeap)) {
			insertHeap(MaxHeap, newNum);
		} else {
			insertHeap(MaxHeap, extractTop(MinHeap));
			insertHeap(MinHeap, newNum);
		}
		curMedian = (getTop(MaxHeap) + getTop(MinHeap))/2;		
	}
	return curMedian;
}

