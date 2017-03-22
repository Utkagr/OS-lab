#include <stdio.h>

int eork(int n){
	
	int i;
	int ppid=0, gpid=0;
	for(i=0;i<n;i++){
		int a=fork();
		if (a) break;
		gpid=ppid;
		ppid = getppid();
	}

	return gpid;
}

int main(){

	int q;
	q = eork(10);
	printf("%d ", getpid());
	printf("%d ", getppid());
	printf("%d\n", q);
	sleep(10);
	return 0;
}