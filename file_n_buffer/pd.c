#include <stdio.h>
#include <fcntl.h>
main(){
	int i;
	FILE *fs;
	char c,d,e;
	fs=fopen("exp","r");
	fscanf(fs,"%c",&c);
	// fflush(stdout);
	d='R';
	read(3,&d,1);
	fscanf(fs,"%c",&e);
	printf("%c%c",c,d);
	printf("%c",e);
}