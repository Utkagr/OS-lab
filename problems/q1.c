// Write a C program which catches the signal by calling the signal function sig_int() for signal SIGINT used to terminate the process.
#include <stdio.h>
#include <signal.h>

void sig_int(){
	printf("Inside function sig_int after catching signal.\n");
}
void main(){
	signal(SIGINT,sig_int);
	for(;;);
}