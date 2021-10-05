#ifndef THREADS_H
#define THREADS_H

#include "q.h"

extern struct TCB_t* runQ;

void startThread(void (*function)(void)){

	//allocate a stack (via malloc) of a certain size (choose 8192)
	void *stack = (void *)malloc(8192);

	//allocate a TCB (via malloc)
	struct TCB_t* thread = (struct TCB_t*)malloc(sizeof(struct TCB_t));

	//call init_TCB with appropriate arguments
	init_TCB(thread, function, stack, 8192);

	//call addQ to add this TCB into the “runQ” which is a global header pointer
	addQueue(&runQ, thread);
}

void run(){
	ucontext_t parent;	// get a place to store the main context, for faking

	getcontext(&parent);	// magic sauce

	swapcontext(&parent, &(runQ->context));	// start the first thread
}

void yield(){
	struct TCB_t* temp = runQ;

	rotateQueue(&runQ);

	swapcontext(&(temp->context), &(runQ->context));
}

#endif
