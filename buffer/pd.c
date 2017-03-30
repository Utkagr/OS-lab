#include <stdio.h>
main(){
	printf("A");
	fork();
	//Buffer is copied to child process
	printf("B");
}