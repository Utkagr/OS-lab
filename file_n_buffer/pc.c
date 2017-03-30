#include <stdio.h>
#include <fcntl.h>
main(){
	int i;
	FILE *fs;
	fs=fopen("exp","w");
	write(3,"PQRST",5);
	fprintf(fs,"A");
	lseek(3,2,0);
	fflush(stdout);
	write(3,"Z",1);
}