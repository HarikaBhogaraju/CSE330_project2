#include <stdio.h>
#include "threads.h"

struct TCB_t* runQ = NULL;

int x = 0;
int y = 0;
int glob = 1;
int loc = 0;


void runTest1(){
	int loc = 0;
		while(1){
			loc++;
			printf("This is %d th execution of thread 1 with global var value % d\n", loc, glob);
			glob++;
			sleep(1);
			yield();
		}
}

void runTest2(){
	int loc = 0;
		while(1){
			loc++;
			printf("This is %d th execution of thread 2 with global var value % d\n", loc, glob);
			glob++;
			sleep(1);
			yield();
		}
}

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
                   	printf("This is %d th execution of thread %d  with global var value % d\n", i,glob,loc);
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
	
	struct TCB_t* threads[x];
        
        InitQueue(&runQ);
        
	for(int i = 0;i<x;i++){
		startThread(runTest);
	}

	run();
	return 0;
	}

}
