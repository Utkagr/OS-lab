#include <stdio.h>
#include <signal.h>
int c=0;
void k(){
	c++;
	if(c==1){
		printf("PP\n");
	}
	else if(c==2){
		printf("QQ\n");
		signal(SIGINT,SIG_DFL);
	}
}
main(){
	signal(SIGINT,k);
	for(;;);
}