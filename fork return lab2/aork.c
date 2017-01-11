#include <stdio.h>
#include <unistd.h>
int aork(){
	int p;
	p=fork();
	if(p==0)
		return(getppid());
	else return(p);
}
int bork(){
	int p=fork(),q,a_id,b_id,c_id;
	if(p==0){
		b_id = getpid();
		return(getppid());
	}
	else{
		a_id = getpid();
		q=fork();
		if(q==0){
			c_id = getpid();
			return(p);
		}
		else
			return(q);
	}
}
int main(){
	int q;
	q=bork();
	printf("%d",getpid());
	printf("%d",getppid());
	printf("%d\n",q);
	sleep(1);
}