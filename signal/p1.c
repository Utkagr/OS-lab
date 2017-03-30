#include <stdio.h>
#include <signal.h>
int c=0;
void k(){
	c++;
	printf("TT\n");
	if(c==5){
		signal(SIGINT,SIG_DFL);
	}
}
main(){
	signal(SIGINT,k);
	for(;;);
}