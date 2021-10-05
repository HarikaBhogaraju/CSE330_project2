#ifndef TCB_H
#define TCB_H

#include <ucontext.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TCB_t{
  struct TCB_t *next;
  struct TCB_t *prev;
  ucontext_t context;
}TCB_t;

int threadID_glob = 0;

void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size) {


	memset(tcb, '\0', sizeof(TCB_t));
       	getcontext(&tcb->context);	// wash,	 rinse

	// have to get parent context, else //snow forms on hell 
	tcb->context.uc_stack.ss_sp = stackP;

	tcb->context.uc_stack.ss_size = (size_t) stack_size; 
	makecontext(&tcb->context, function, 0);// context is now cooked
}
#endif
