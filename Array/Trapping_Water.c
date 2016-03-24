#include <stdlib.h>
#include <stdio.h>

#define MAXMIN(first, opr, second) (first opr second) ? first : second
//#define MIN(first, second) (first<second)? first : second

void printArray(int *array, int size)
{
	int i = 0;
	printf("\n********Array**********\n");
	for (i = 0; i < size; i++)
	{
		printf("%d,",array[i]);
	}
	printf("\n");
}
int calcTrappedWater(int *array, int size)
{
	if(size <= 0)
		return 0;
	
	int *left = (int *)calloc(size, sizeof(int));
	int *right = (int *)calloc(size, sizeof(int));
	int i = 0, trappedWater = 0;
	int temp = 0;

	left[0] = 0;
	right[size-1] = 0;

	for(i = 1; i < size; i++)
	{
		left[i] = MAXMIN(array[i-1], >, left[i-1]);
	}
	printArray(left, size);
	for(i = size-2; i >= 0; i--)
	{
		right[i] = MAXMIN(array[i+1], > ,right[i+1]);
	}
	printArray(right, size);
	for(i = 1; i < size-1; i++)
	{
		temp = MAXMIN(left[i], <, right[i]);
	
		if (temp-array[i] > 0)
			trappedWater+=temp-array[i];
	}
	free(left);
	free(right);
	return trappedWater;
}
int main ()
{
	int input_array[ ] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int size = sizeof(input_array)/sizeof(input_array[0]);
	
	printf("Amount of water trapped: %d\n", calcTrappedWater(input_array, size));

	return 0;
}
