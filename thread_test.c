/*
* Fatimah Alyousef
* CSE 330, Project2
*/

#include "threads.h"
#include <unistd.h>	//for linux

int globalCount = 0, numOfThreads, it; //it is the number of time each thread should be exctuted

void thread1() {
	//thread keeps track of the number of threads
	//localCount keeps track of the number of execution of each thread
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
	RunQ = (struct queue*)malloc(sizeof(queue));
	InitQueue(RunQ);

	scanf("%d,%d", &numOfThreads, &it); //read input

	if (numOfThreads == 0) {
		printf("No Threads\n");
	}

	start_thread(&thread1);
	run();


	return 0;
}
