#include <stdio.h>
#include <signal.h>

void k(){
	int a;
	printf("You want to continue?\n");
	scanf("%d",&a);
	int b=3/a;
	// if(a==0){
		// kill(getpid(),SIGQUIT);
		// signal(SIGINT,SIG_DFL);
	// }
	// else{}
}
main(){
	signal(SIGINT,k);
	for(;;);
}