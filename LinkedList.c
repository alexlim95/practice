/*
 * LinkedList.c
 *
 *  Created on: Sep 8, 2017
 *      Author: Alex Lim
 *
 *  Description: Basic singly linked list with user input to append
 *  to head element dynamically.
 */

#include <stdlib.h>
#include <stdio.h>

// the type for the node that makes up the body of the list
struct node {
	int data;			// data
	struct node *next;		// node pointer
};

// create a NULL pointer (head) of data type node
struct node *head = NULL;

// declare functions
void append_Head(int element);

int main()
{
	int number = 0;

	// keeps asking for user input to append to linked list until a -1 is entered
	while(1)
	{
		printf("Enter element to append to head (-1 to end): \n");
		scanf("%d", &number);						// user input for number
		if(number == -1) return 0;
		else append_Head(number);					// passes input and appends to head
	}
	return 0;		// ends program
}

void append_Head(int element){

	// creates a pointer to newNode object of node data type
	struct node *newNode;

	// allocates a block of memory in the "heap" and
	// returns a pointer to the new block.
	// argument is integer size of the block in bytes
	newNode = malloc(sizeof(struct node));
	// assigns element to newNode data
	newNode->data = element ;
	// links newNode next as head
	newNode->next = head;

	// newNode is now the head of the link list
	head = newNode;

	// prints linked list
	// create new pointer object of data type node
	struct node *ptr = head;
	// start from the beginning scan until reaches NULL next pointer (end of list)
	while(ptr != NULL){
		printf("(%d) ",ptr->data);	// prints data element that ptr points to
		ptr = ptr->next;			// point to next element
	}
}

