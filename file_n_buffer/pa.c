#include <stdio.h>
#include <fcntl.h>
main(){
	FILE *fs;
	fs=fopen("exp","w");
	fprintf(fs,"pqr");
	//fprintf prints in the file.
	write(3,"Y",1);
	//Write doesnot uses buffer.
}
