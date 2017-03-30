#include <stdio.h>
main(){
	int i;
	//Idea is that it is not necessary that output be immediately shown on the monitor.
	//The output is put into buffer. The contents of the buffer are displayed later.
	printf("A");
	scanf("%d",&i);
	//If we put a \n or scanf("%d",&i) or fflush(stdout)in the above print statement.it will clear the buffer immediately.
	sleep(1);
	printf("B");
	sleep(2);
}