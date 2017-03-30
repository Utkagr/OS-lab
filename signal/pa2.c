#include <stdio.h>
#include <signal.h>
// int c=0;
void k(){
	// c++;
	printf("AA\n");
	// printf("%d",c);
	// fflush(stdout);
	signal(SIGINT,SIG_DFL);
	// sleep(1);
}
main(){
	signal(SIGINT,k);
	for(;;);
}