#include <stdio.h>
main(){
	int p,q;
	p=fork();
	q=fork();
	printf("%d %d %d %d %d \n",p,q,getpid(),getpgrp(),getppid());
	sleep(1);
}