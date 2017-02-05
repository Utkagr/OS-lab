#include <stdio.h>
#include <fcntl.h>

main(){
	int fd,i,j=0;
	char c;
	fd = open("xyz",O_RDONLY);
	lseek(fd,0,0);
	while(i=read(fd,&c,1)){
		printf("%c",c);	
	}
}