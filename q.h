#include <stdlib.h>
#include <stddef.h>
#include <ucontext.h>
#include "tcb.h"

void InitQueue(struct TCB_t **head);
struct TCB_t* newItem();
void addQueue(struct TCB_t **head, struct TCB_t *item);
struct TCB_t* delQueue(struct TCB_t **head);
void rotateQueue(struct TCB_t **head);
void freeItem(void *item);
void printQueue(struct TCB_t *headPtr);
