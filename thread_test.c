#include <stddef.h>
#include <stdlib.h>
#include <ucontext.h>
#include <stdio.h>
#include <string.h>
#include "threads.h"

struct TCB_t* runQ = NULL;

int x = 0;
int y = 0;
int glob = 0;


void runTest1(){
	int loc = 0;
		while(1){
			printf("This is %d th execution of thread 1 with global var value % d", loc, glob);
			glob++;
			sleep(1);
			yield();
		}
}

void runTest2(){
	int loc = 0;
		while(1){
			loc++;
			printf("This is %d th execution of thread 2 with global var value % d", loc, glob);
			glob++;
			sleep(1);
			yield();
		}
}

void runTest3(){
	int loc = 0;
		while(1){
			loc++;
			printf("This is %d th execution of thread 3 with global var value % d", loc, glob);
			glob++;
			sleep(1);
			yield();
		}
}

int main(int argc, char **argv){

	char str[100];

	FILE* f = fopen(argv[1], "r");

	fgets(str,100,f);

	char* first = strtok(str, ",");
  char* second = strtok(NULL, ",");

	x = atoi(first);
	y = atoi(second);

	struct TCB_t* threads;
	threads = (struct TCB_t*)calloc(x+1,sizeof(struct TCB_t));

	InitQueue(&runQ);

	for(int i = 0;i<x;i++){
		if(i % 3 == 1){
			startThread(&threads[i],runTest1);
		}
		if(i % 3 == 2){
			startThread(&threads[i],runTest2);
		}
		if(i % 3 == 0){
			startThread(&threads[i],runTest3);
		}
	}

	run();

}
