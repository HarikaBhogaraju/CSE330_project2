//Harika Bhogaraju
//1216938606
#include "q.h"

struct first* RunQ;

void startThread(void (*function)(void)){
	//	allocate a stack(via malloc) of a certain size(choose 8192)
	void* stack_pointer = (void*)malloc(8192);
	//	allocate a TCB(via malloc)
	TCB_T* tcb = (TCB_T*)malloc(sizeof(TCB_T));
	//	call init_TCB with appropriate arguments
	init_tcb(tcb, function, stack_pointer, 8192);
	//	call addQ to add this TCB into the "RunQ" which is a global first_element pointer
	AddQueue(RunQ, tcb);
}

void run(){
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent, &(RunQ->first_element->context));
}

void yield(){
	ucontext_t prev;
	getcontext(&prev);
	RotateQ(RunQ);
	swapcontext(&(RunQ->first_element->prev->context), &(RunQ->first_element->context));
}
