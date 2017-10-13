#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *func1(void * vargp){
	// sleep(1);
	printf("Inside thread\n");
	// return NULL;
	// pthread_exit(NULL);
}
int main(){
	pthread_t t1;
	printf("Creating thread..\n");	
	pthread_create(&t1,NULL,func1,NULL);
	sleep(1);
	printf("Thread and main process are both running.Join statement follows.\n");
	pthread_join(t1,NULL);
	printf("Thread has executed\n");
	pthread_exit(NULL);
	return 0;
}