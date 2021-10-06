
#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"

	struct first{
		TCB_T* first_element;
	}first;


	TCB_T* newItem() {
		TCB_T* item = (TCB_T*)malloc(sizeof(TCB_T));
		item->prev = NULL;
		item->next = NULL;
		return item;
	}


	void InitQueue(struct queue* head) {
		head->first_element = NULL;
	}


	void AddQueue(struct queue* head, struct TCB_T* item) {
		if (head->first_element == NULL) {

			head->first_element = item;
			head->first_element->prev = item;
			head->first_element->next = item;
    }
		else {
			struct TCB_T* tail = head->first_element->prev;
			item->next = head->first_element;
			item->prev = tail;
			head->first_element->prev = item;
			tail->next = item;
		}
	}

	TCB_T* DeleteQueue(struct queue* head) {
		TCB_T* temp = (TCB_T*)malloc(sizeof(TCB_T));
		temp = head->first_element;

		if (head->first_element != NULL) {
			if (head->first_element->next == NULL) {
				head->first_element = NULL;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->next->prev = temp->prev;
				head->first_element = temp->next;
			}
		}

		return temp;
	}

	void RotateQ(struct queue* head) {
		AddQueue(head, DeleteQueue(head));
	}

	void FreeItem(struct q_element* item) {
		free(item);
	}
