#include <stdio.h>
#include <unistd.h>

int main(){
	int p=fork();
	int q=fork();
	if(p==0) fork();
	fork();
	printf("X");
	sleep(6);
}