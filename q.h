/*
Fatimah Alyousef
CSE 330, Project2
Fall 2021
*/

#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"


	struct  q_element {
		struct q_element* prev;
		struct q_element* next;
		int payLoad;
	};

	struct queue {
		TCB_T* header; //header is a pointer to the first element of the queue.
	}queue;

	//1.	item = NewItem(); // returns a pointer to a new q-element
	TCB_T* newItem() {
		TCB_T* newElement = (TCB_T*)malloc(sizeof(TCB_T));
		newElement->prev = NULL;
		newElement->next = NULL;
		return newElement;
	}

	//2.	InitQueue(&head) // creates a empty queue, pointed to by the variable head.
	void InitQueue(struct queue* head) {
		head->header = NULL;
	}

	//3.	AddQueue(&head, item) // adds a queue item, pointed to by item, to the queue pointed to by head.
	void AddQueue(struct queue* head, struct TCB_T* item) {
		if (head->header == NULL) {
			//Base case: if the queue is empty
			head->header = item;			// head points to first element
			head->header->prev = item;	// prev should point at itself
			head->header->next = item;	// next points to itself
		}
		else {
			struct TCB_T* tail = head->header->prev;
			item->next = head->header;	// next points to head
			item->prev = tail;			// link first element to last element
			head->header->prev = item; 	// set head tail to item
			tail->next = item;			// make old tail next point to item
		}
	}

	//4.	item = DelQueue(&head) // deletes an item from head and returns a pointer to the deleted item
	TCB_T* DelQueue(struct queue* head) {
		TCB_T* temp = (TCB_T*)malloc(sizeof(TCB_T));
		temp = head->header; //save first element

		if (head->header != NULL) {
			//Base case: if the queue has one element
			if (head->header->next == NULL) {
				head->header = NULL;
			}
			else {
				temp->prev->next = temp->next; //second node prev points to third node
				temp->next->next->prev = temp->prev; //third node points to second node
				head->header = temp->next;
			}
		}

		return temp;
	}

	//5.	RotateQ(&head) // Moves the header pointer to the next element in the queue.
	void RotateQ(struct queue* head) {
		AddQueue(head, DelQueue(head));
	}

	void FreeItem(struct q_element* item) {
		free(item);
	}
