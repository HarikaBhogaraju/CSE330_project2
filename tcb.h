#include <ucontext.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct TCB_t{
  struct TCB_t *next;
  struct TCB_t *prev;
  ucontext_t context;
}TCB_t;

void init_TCB (TCB_t *tcb, void *function, void *stackP, int stack_size);
