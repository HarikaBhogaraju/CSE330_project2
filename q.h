#ifndef Q_H
#define Q_H

#include <stdio.h>
#include "tcb.h"


struct TCB_t* RunQ;

void InitQueue(struct TCB_t** head){
        *head = NULL;
}

struct TCB_t* newItem(){
        struct TCB_t* item = (struct TCB_t*)malloc(sizeof(struct TCB_t));
        return item;
}

void addQueue(struct TCB_t** head, struct TCB_t* item){
        TCB_t* temp = (struct TCB_t*)malloc(sizeof(struct TCB_t));
	temp = *head;
	
        if (temp == NULL){
                *head = item;
                (*head)->next = *head;
                (*head)->prev = *head;
        }
        else if (temp->next == temp){
                temp->next = item;
                temp->prev = item;
                item->next = temp;
                item->prev = temp;
        }
        else{
                while (temp->next != *head)
                        temp = temp->next;
                        item->next = temp->next;
                        item->prev = temp;
                        temp->next = item;
                        (*head)->prev = item;
        }
}

struct TCB_t* delQueue(struct TCB_t** head){
        TCB_t* deletedItem = (struct TCB_t*)malloc(sizeof(struct TCB_t));
	deletedItem = *head;
        if (deletedItem->next == deletedItem) {
                *head = NULL;
        } else {
                while (deletedItem->next != *head) {
                        deletedItem = deletedItem->next;
                }
                deletedItem->prev->next = deletedItem->next;
                deletedItem->next->prev = deletedItem->prev;
        }
        return deletedItem;
}

void rotateQueue(struct TCB_t** head){
        if (head != NULL) {
                TCB_t* temp = (struct TCB_t*)malloc(sizeof(struct TCB_t));
		temp = *head;
                *head = temp->next;
        }
}
void freeItem(void *item){
        free(item);
}
void printQueue(struct TCB_t *head){
        if (head == NULL) {
                printf("head is null");
                return;
        }
        if (head->next == head) {
                printf("\t%p\n", head);
        } else {
                TCB_t *current = head;
                do {
                        printf("\t%p\n", current);
                        current = current->next;
                } while (current != head);
	}
}

#endif
