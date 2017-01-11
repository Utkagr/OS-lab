#include <stdio.h>
#include <math.h>
#include <unistd.h>

double log_func(double x){
	return log(x)/log(2);
}
int main(){
	double n,x;
	//n - additional processes
	printf("enter the number n");
	scanf("%ld",&n);
	x=n+1;
	//x - total processes
	int m=log_func(n)+1;
	//m - number of forks
	// if(x%2 == 0){
	// 	int cf = log_func(x)+1; //count forks
	// 	while(cf!=0){
	// 		cf--;
	// 		fork();
	// 		printf("%d ".getpid());
	// 	}

	// }
	while(n != 0){
	}
}