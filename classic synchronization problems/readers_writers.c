#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t read_lock,write_lock;
int shared_var = 0;
int readers_count = 0;

void* readers(void* vargp){
	sleep(1);
	int p = (intptr_t)vargp;
	printf("Reader %d wants to read the shared variable\n",p);
	//reader wants to enter
	sem_wait(&read_lock); //if granted reader will enter
	//increase readers count
	readers_count++;
	//check if it is the first one
	if(readers_count==1){
		sem_wait(&write_lock);
	}
	printf("Data read by reader %d is %d.\n",p,shared_var);
	//reader reads
	//other readers are allowed to join
	sem_post(&read_lock);
	//reader wants to exit
	sem_wait(&read_lock);
	//decrease readers count
	readers_count--;
	//check if it was the last one
	if(readers_count==0){
		sem_post(&write_lock);
	}
	printf("Reader %d is leaving the database\n",p);
	sem_post(&read_lock); //reader leaves
	// pthread_exit(NULL);
}
void* writers(void* vargp){
	sleep(1);
	int q = (intptr_t)vargp;
	//writer wants to write
	printf("Writer %d wants to write to shared variable\n",q);
	sem_wait(&write_lock);
	//writer writes
	shared_var++;
	printf("Data written by writer %d is %d\n",q,shared_var);
	//writer wants to leave
	sem_post(&write_lock);
	printf("Writer %d leaves\n",q);
	// sleep(1);
	// pthread_exit(NULL);
}
int main(){
	pthread_t r[2],w[2];
	int i;
	//initialize semaphores
	sem_init(&read_lock,0,1);
	sem_init(&write_lock,0,1);
	//create threads
	for(i=0;i<2;i++){
		pthread_create(&r[i],NULL,readers,(void *)(intptr_t)i);
		pthread_create(&w[i],NULL,writers,(void *)(intptr_t)i);
	}
	//wait for threads to finish
	for(i=0;i<2;i++){
		pthread_join(r[i],NULL);
		pthread_join(w[i],NULL);
	}
	// pthread_exit(NULL);
	return 0;
}
/*
Output of the program for 2 readers and 2 writers

Writer 0 wants to write to shared variable
Data written by writer 0 is 1
Writer 0 leaves
Reader 0 wants to read the shared variable
Data read by reader 0 is 1.
Reader 0 is leaving the database
Reader 1 wants to read the shared variable
Data read by reader 1 is 1.
Reader 1 is leaving the database
Writer 1 wants to write to shared variable
Data written by writer 1 is 2
Writer 1 leaves
*/