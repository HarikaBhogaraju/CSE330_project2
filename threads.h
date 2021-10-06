#include "q.h"

struct queue* RunQ;

void start_thread(void (*function)(void))
{
	//printf("this is start_thread() function\n");

	void* stack_pointer = (void*)malloc(8192);		//	allocate a stack(via malloc) of a certain size(choose 8192)

	TCB_T* tcb = (TCB_T*)malloc(sizeof(TCB_T)); 	//	allocate a TCB(via malloc)

	init_tcb(tcb, function, stack_pointer, 8192);	//	call init_TCB with appropriate arguments

	AddQueue(RunQ, tcb);							//	call addQ to add this TCB into the "RunQ" which is a global header pointer
}

void run()
{
	//printf("this is run() function\n");
	ucontext_t parent;	// get a place to store the main context, for faking
	getcontext(&parent);	// magic sauce
	swapcontext(&parent, &(RunQ->header->context));	// start the first thread
}

void yield() // similar to run
{
	/*rotate the run Q;
	swap the context, from previous thread to the thread pointed to by RunQ*/
	ucontext_t prev;
	getcontext(&prev);
	RotateQ(RunQ);
	swapcontext(&(RunQ->header->prev->context), &(RunQ->header->context));

}
