#include <stdio.h>
#include "threads.h"

struct TCB_t* runQ = NULL;

int x = 0;
int y = 0;
int glob = 0;


void runTest1(){
	int loc = 1;
		while(1){
			printf("This is %d th execution of thread 1 with global var value % d\n", loc, glob);
			glob++;
			sleep(1);
			yield();
		}
}

void runTest2(){
	int loc = 1;
		while(1){
			loc++;
			printf("This is %d th execution of thread 2 with global var value % d\n", loc, glob);
			glob++;
			sleep(1);
			yield();
		}
}

void runTest3(){
	int loc = 1;
		while(1){
			loc++;
			printf("This is %d th execution of thread 3 with global var value % d\n", loc, glob);
			glob++;
			sleep(1);
			yield();
		}
}

int main(){

	x = 2;
	y = 3;

	//printf("MAIN CALLED\n");

	if(x == 0){
		printf("No Threads\n");
		return 0;
	}
	else{
	//printf("else entered\n");
	struct TCB_t* threads[x];
        //threads = (struct TCB_t*)calloc(x+1,sizeof(struct TCB_t));
        //printf("threads allocated\n");
        InitQueue(&runQ);
        //printf("InitQ executed\n");

	for(int i = 0;i<x;i++){
		if(i % 3 == 1){
			//printf("runtest1 called\n");
			startThread(runTest1);
		}
		if(i % 3 == 2){
			 //printf("runtest2 called\n");
			startThread(runTest2);
		}
		if(i % 3 == 0){
			 //printf("runtest3 called\n");
			startThread(runTest3);
		}
	}

	run();
	return 0;
	}

}
