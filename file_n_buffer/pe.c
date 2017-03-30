#include <stdio.h>
#include <fcntl.h>
main(){
	FILE *fs;
	int i;
	char c;
	fs=fopen("pqr","r+");
	fscanf(fs,"%c",&c);
	printf("%c",c);

	write(3,"KKKKKK",6);
	i=lseek(3,-2,1);
	lseek(3,i,0);

	fscanf(fs,"%c",&c);
	printf("%c",c);
	fflush(fs);
	fscanf(fs,"%c",&c);
	printf("%c",c);
}