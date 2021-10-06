#include <stdio.h>
#include "threads.h"

struct TCB_t* runQ = NULL;

int x = 0;
int y = 0;
int glob = 1;
int loc = 0;

void read_ints (const char* file_name)
{
  FILE* file = fopen (file_name, "r");
  fscanf(file,"%d,%d",&x,&y);
  fclose (file);
}

void runTest(){
	for(int i = 1;i<=y;i++){
			loc = loc + glob;
			printf("\n");
      printf("This is %d th execution of thread %d with global var value %d\n", i,glob,loc);
			if(glob == x){
				glob = 1;
			}
			else{
				glob++;
			}
      sleep(1);
      yield();
	}
}

int main(int argc, char** argv){

	read_ints(argv[1]);

	if(x == 0){
		printf("No Threads\n");
		return 0;
	}
	else{

	  InitQueue(&runQ);
		printf("\n");
		for(int i = 0;i<x;i++){
			startThread(runTest);
		}
		printf("\n");
		run();
		return 0;
	}

}
