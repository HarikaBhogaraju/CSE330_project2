#include "threads.h"
#include <unistd.h>

int glob = 0;
int x = 0; //num of threads
int y = 0; //execute each time

void runTest() {

	int loc = 1, i = 1;

	while (i <= x && loc <= y) {
		glob = glob+i;

		printf("\n This is %d th execution of thread %d with global var value %d \n", loc, i, glob);

		yield();

		i++;

		if (i > x) {
			loc++;
			i = 1;
		}

	}

}

int main() {
	RunQ = (struct first*)malloc(sizeof(first));
	InitQueue(RunQ);

	scanf("%d,%d", &x, &y); //read input

	if (x == 0) {
		printf("No Threads\n");
	}

	startThread(&runTest);
	run();


	return 0;
}
