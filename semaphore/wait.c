#include <stdio.h>
//https://en.wikibooks.org/wiki/Operating_System_Design/Processes/Semaphores
//Producer-Consumer problem https://en.wikipedia.org/wiki/Producer%E2%80%93consumer_problem
//Wait is called when a process wants to access shared resources
//or basically critical section
void wait(Semaphore s){
	// while(s==0);
//The while function above creates a condition of busy waiting which is also called spinlock
//for which a queue of waiting processes is created and a wakeup fn is created,
//New updatted fn should look like
	s=s-1;
	if(s<0){
		//add process to queue
		block();
	}
}
//Signal is called when a process is done using critical section or shared resources.
void signal(Semaphore s){
	//Either call the wakeup function
	//or increment semaphore
	s=s+1;
	if(s>=0){
		//remove process p from queue
		wakeup(p);
	}
}
void Init(Semaphore s,Int v){
	s=v;
}
//Example of mutual exclusion using binary semaphores
// do
// {
//     wait(s);
//     // critical section
//     signal(s);
//     // remainder section
// } while(1);
int main(int argc, char const *argv[])
{
	/* code */
	int i=0;
	while(i==0);
	printf("X");
	return 0;
}
// It is important to note that though mutex seems to work as a semaphore with value of 1 (binary semaphore), 
// but there is difference in the fact that mutex has ownership concept. 
// Ownership means that mutex can only be "incremented" back (set to 1) by the same process 
// that "decremented" it (set to 0), and all others tasks wait until mutex is available for 
// decrement (effectively meaning that resource is available), which ensures mutual exclusivity and avoids deadlock.
// Thus using mutexes improperly can stall many processes when exclusive access is not required, 
// // but mutex is used instead of semaphore