#include <stdio.h>
#include <unistd.h>

int main(){
	int p,q;
	p=fork();
	fork();
	q=fork();
	if(p==q)
		printf("X");
	else printf("Y");
}