/* Add 2 Number represented by 2 Linklist O(m+n)
Author: Nitesh Gami
Created: 28-FEB-2016
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} tNode;

tNode * newNode (int data) {
	tNode *newNode = (tNode *)malloc(sizeof(tNode));
	if(!newNode) {
		printf("Malloc Failed");
		return NULL;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int addtoFirst (tNode **head, tNode *addNode) {
	
	if(!head || !addNode) {
		printf("head or addNode is NULL");
		return -1;
	}
	addNode->next = *head;
	*head = addNode;
	return 0;	
}

void addListUtility (tNode *FirstLL, tNode *SecondLL, tNode **ResultLL, int *carry) {

	int sum = -1;
	tNode *tempNode = NULL;

	if(!ResultLL || !FirstLL)
		return;

	addListUtility(FirstLL->next, SecondLL->next, ResultLL, carry);
	
	sum = FirstLL->data + SecondLL->data + *carry;
	tempNode = newNode(sum%10);
	addtoFirst(ResultLL, tempNode);
	*carry = sum/10;
	return;
}

int sizeLL(tNode *head) {
	int count = 0;
	while (head){
		count++;
		head = head->next;			
	}
	return count;
}

tNode* moveListbyPosition(tNode* head, unsigned int position) {
	tNode *temp = head;
	
	while(temp && position) {
		temp = temp->next;
		position--;
	}
	return temp;	
}

void addListRemaining (tNode *bigLL, tNode **Result, int position, int *carry) {

	int sum = -1;
	tNode *tempNode = NULL;
	if(!bigLL || !Result || (position <= 0)) {
		return;
	}

	addListRemaining(bigLL->next, Result, position-1, carry);
	sum = bigLL->data + *carry;
	tempNode = newNode(sum%10);
	*carry = *carry/10;
	addtoFirst(Result, tempNode);
	return;
}

tNode * addList(tNode *FirstLL, tNode *SecondLL) {
	/*O(m+n+n+m-n+1) = O(2m+n+1) = O(m+n) */
	int SizeFirstLL = sizeLL(FirstLL); /* O(m) */
	int SizeSecondLL = sizeLL(SecondLL); /* O(n) */
	tNode *bigLL, *smallLL = NULL;
	int carry = 0;
	tNode *resultLL = NULL;

	if (SizeFirstLL == 0) {
		resultLL = SecondLL;
	} else if(SizeSecondLL == 0) {
		resultLL = FirstLL;
	} else {
		if (SizeFirstLL >= SizeSecondLL) {
			bigLL = FirstLL;
			smallLL = SecondLL;
		} else {
			bigLL = SecondLL;
			smallLL = FirstLL;
		}
		tNode *tempLL = NULL;
		tempLL = moveListbyPosition(bigLL, (unsigned int )abs(SizeFirstLL-SizeSecondLL)); /*O(m-n)*/
	
		addListUtility(tempLL, smallLL, &resultLL, &carry); /* O(n) */
		addListRemaining(bigLL, &resultLL, abs(SizeFirstLL-SizeSecondLL), &carry); /*O(m-n) */
	
		if(carry > 0) {
			tempLL = newNode(carry); /*O(1) */
			addtoFirst(&resultLL, tempLL);
		}
	}
	return resultLL;
}
void printLL (tNode *head) {
	printf("\n******");
	while (head) {
		printf("%d-->",head->data);
		head = head->next;	
	}
	printf("*******\n");	
}

int main() {
	tNode *FirstLL = NULL;
	tNode *resultLL, *SecondLL = NULL;
	tNode *temp = newNode(5);
	addtoFirst(&FirstLL, temp);
	temp = newNode(6);
	addtoFirst(&FirstLL, temp);
	temp = newNode(7);	
	addtoFirst(&FirstLL, temp);
	temp = newNode(8);
	addtoFirst(&FirstLL, temp);
	temp = newNode(9);
	addtoFirst(&FirstLL, temp);
	printLL(FirstLL);	

	temp = newNode(9);
	addtoFirst(&SecondLL, temp);
	temp = newNode(8);
	addtoFirst(&SecondLL, temp);
	temp = newNode(7);	
	addtoFirst(&SecondLL, temp);
	temp = newNode(6);
	addtoFirst(&SecondLL, temp);
	temp = newNode(5);
	addtoFirst(&SecondLL, temp);
	printLL(SecondLL);	

	resultLL = addList(FirstLL, SecondLL);
	printLL(resultLL);

	return 0;
}

