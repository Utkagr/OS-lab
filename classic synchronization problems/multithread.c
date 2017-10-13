#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int g=0;
void* fun1(void* vargp){
	int* tid = (int*)vargp;
	static int s = 0;
	s++;g++;
	printf("ThreadID: %d, Static Var: %d, Global var: %d\n",*tid,s,g);
}
int main(){
	pthread_t id;
	int* i;
	for(*i=0;*i<3;(*i)++){
		pthread_create(&id,NULL,fun1,(void *)i);
	}
	// pthread_exit(NULL);
	return 0;
}