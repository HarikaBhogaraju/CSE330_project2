//Harika Bhogaraju
//1216938606
#include <stdio.h>
#include <stdlib.h>
#include "tcb.h"

	struct q{
		TCB_T* element;
	}q;

	TCB_T* newItem() {
		TCB_T* item = (TCB_T*)malloc(sizeof(TCB_T));
		return item;
	}


	void InitQueue(struct first* head) {
		head->element = NULL;
	}


	void AddQueue(struct first* head, struct TCB_T* item) {
		if (head->element == NULL) {
			head->element = item;
			head->element->prev = item;
			head->element->next = item;
    }
		else {
			struct TCB_T* tail = head->element->prev;
			item->next = head->element;
			item->prev = tail;
			head->element->prev = item;
			tail->next = item;
		}
	}

	TCB_T* DeleteQueue(struct first* head) {
		TCB_T* temp = (TCB_T*)malloc(sizeof(TCB_T));
		temp = head->element;

		if (head->element != NULL) {
			if (head->element->next == NULL) {
				head->element = NULL;
			}
			else {
				temp->prev->next = temp->next;
				temp->next->next->prev = temp->prev;
				head->element = temp->next;
			}
		}

		return temp;
	}

	void RotateQ(struct first* head) {
		AddQueue(head, DeleteQueue(head));
	}
