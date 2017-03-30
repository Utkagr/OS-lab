#include <stdio.h>
#include <signal.h>
int c=0;
void k(){
	c++;
	if(c%2==1){
		printf("PP\n");
	}
	if(c%2==0){
		printf("QQ\n");
	}
}
main(){
	signal(SIGINT,k);
	for(;;);
}