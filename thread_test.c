//Harika Bhogaraju
//1216938606

#include "threads.h"
#include <unistd.h>

int glob = 0;
int x = 0; //num of threads
int y = 0; //execute each time

void runTest() {

	int loc = 1, i = 1;
	for(i = 1;i<=x;){

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

void read_int(){

		scanf("%d,%d", &x, &y);
}

int main() {
	RunQ = (struct q*)malloc(sizeof(q));
	InitQueue(RunQ);

	read_int();

	if (x == 0) {
		printf("No Threads\n");
	}

	startThread(&runTest);
	run();


	return 0;
}
