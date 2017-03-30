#include <stdio.h>
#include <fcntl.h>
main(){
	int i;
	FILE *fs;
	fs = fopen("exp","w");
	for(i=1;i<=410;i++){
		fprintf(fs,"abcdefghij");
	}
}