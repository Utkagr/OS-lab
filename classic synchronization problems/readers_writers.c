#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t read_lock,write_lock;
int shared_var = 0;
int readers_count = 0;

void* readers(void* vargp){
	int* p;
	p = (int*)vargp;
	//reader wants to enter
	sem_wait(&read_lock); //if granted reader will enter
	//increase readers count
	readers_count++;
	//check if it is the first one
	if(readers_count==1)
		sem_wait(&write_lock);
	//reader reads
	//other readers are allowed to join
	sem_post(&read_lock);
	// printf("Data read by the reader %d.\n",*p);
	//reader wants to exit
	sem_wait(&read_lock);
	//decrease readers count
	readers_count--;
	//check if it was the last one
	if(readers_count==0)
		sem_post(&write_lock);
	sem_post(&read_lock); //reader leaves
	pthread_exit(NULL);
}
void* writers(void* vargp){
	int* q = (int*)vargp;
	//writer wants to write
	sem_wait(&write_lock);
	//writer writes
	shared_var++;
	printf("Data written by writer %d is %d\n",*q,shared_var);
	sleep(1);
	//writer wants to leave
	sem_post(&write_lock);
	pthread_exit(NULL);
}
int main(){
	pthread_t r[2],w[2];
	int* a;
	int* b;
	//initialize semaphores
	sem_init(&read_lock,0,1);
	sem_init(&write_lock,0,1);
	//create threads
	for(int i=0;i<2;i++){
		pthread_create(&r[i],NULL,readers,(void*)a);
		pthread_create(&w[i],NULL,writers,(void*)b);
	}
	//wait for threads to finish
	for(int i=0;i<2;i++){
		pthread_join(r[i],NULL);
		pthread_join(w[i],NULL);
	}
	// pthread_exit(NULL);
	return 0;
}