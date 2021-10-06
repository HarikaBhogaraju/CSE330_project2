
#include "threads.h"
#include <unistd.h>

int globalCount = 0, numOfThreads, it;

void runTest() {

	int localCount = 1, thread = 1;

	while (thread <= numOfThreads && localCount <= it) {
		globalCount += thread;

		printf("\n This is %d th execution of thread %d with global var value %d \n", localCount, thread, globalCount);
		yield();

		thread++;
		if (thread > numOfThreads) {
			localCount++;
			thread = 1;
		}
	}
}

int main() {
	RunQ = (struct TCB_t*)malloc(sizeof(TCB_t));
	InitQueue(&RunQ);

	scanf("%d,%d", &numOfThreads, &it); //read input

	if (numOfThreads == 0) {
		printf("No Threads\n");
	}

	start_thread(runTest);
	run();


	return 0;
}
