#include <stdio.h>
#include <fcntl.h>

main(){
	int fd,i,j,k;
	char c;
	fd=open("xyz",O_RDONLY);
	i=lseek(fd,-1,2);
	lseek(fd,i,0);
	while(j=read(fd,&c,1)){
		printf("%c",c);
		k=lseek(fd,-2,1);
		lseek(fd,k,0);
	}
}