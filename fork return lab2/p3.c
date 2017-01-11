#include <stdio.h>
#include <unistd.h>

int main(){
	int p=fork();
	if (p!=0) printf("%d\n", p);

	int q = fork();
	if (q!=0) printf("%d\n", q);

	int r=0;
	if (p==0) r=fork();
	if (r!=0) printf("%d\n", r);

	int s;
	if (p==0 || q==0 || r==0) s=fork();
	if (s!=0) printf("%d\n", s);

	return 0;
}