#include <stdio.h>
#include <signal.h>
int c=0;
void k(){
	c++;
	printf("AA\n");
	printf("%d\n",c);
	// \n also empties buffer
	// fflush(stdout);
	// sleep(1);
}
main(){
	signal(SIGINT,k);
	for(;;);
}