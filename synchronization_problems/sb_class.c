#include <stdio.h>
#include <pthread.h>

#define CHAIRS 5

typedef int semaphore;

semaphore customers =0;
semaphore barbers =0;
semaphore mutex = 1;
int waiting = 0;

void down(int* con_var){
	while(*con_var==0){
		//go to sleep
		sleep(2);
	}
	(*con_var)--;
}
void up(int* con_var){
	if((*con_var==0)&&(barbers != 0)){
		//barber must be sleeping.
		printf("Waking up barber..\n");
		return;
	}
	(*con_var)++;
}
void cut_hair(){
	printf("Barber is cutting hair..\n");
}
void get_haircut(){
	printf("Be seated and be serviced.\n");
}
void *barber(void *_){

	while(customers <= 5){
		down(&customers);
		printf("Customers: %d\n",customers);
		down(&mutex);
		waiting = waiting - 1;
		up(&barbers);
		printf("Barbers: %d\n",barbers);
		up(&mutex);
		cut_hair();
		// sleep(2);
	}
}
void *customer(void *_){
	down(&mutex);
	printf("Acquiring lock..");
	//enter critical region
	while(1){
	if(waiting < CHAIRS){
		waiting = waiting + 1;
		printf("Waiting: %d\n",waiting);
		up(&customers);
		printf("Customers: %d\n",customers);
		up(&mutex);
		down(&barbers);
		printf("Barbers: %d\n",barbers);
		get_haircut();
	}
	else{
		up(&mutex);
		printf("Shop is full.Do not wait.\n");
	}		
	}
}
void main(){
	pthread_t b;
	pthread_t c;
	pthread_create(&b,NULL,barber,NULL);	
	pthread_create(&c,NULL,customer,NULL);
	// pthread_join(c,NULL);
	pthread_join(b,NULL);
}