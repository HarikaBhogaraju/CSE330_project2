#include <ucontext.h>
#include "tcb.h"
void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size) {

  memset(tcb, '\0', sizeof(TCB_t));

  getcontext(&tcb->context); // wash, rinse

  // have to get parent context,else snow forms on hell

  tcb->context.uc_stack.ss_sp = stackP;

  tcb->context.uc_stack.ss_size = sizeof(stack_size);

  makecontext(&tcb->context, function, 0); // context is now cooked

}
