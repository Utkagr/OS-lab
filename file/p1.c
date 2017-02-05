#include <stdio.h>
#include <fcntl.h>

main(){
	int fd,i=0;
	char c;
	fd=open("xyz",O_RDONLY);
	lseek(fd,0,0);
	while(c!='a'){
	read(fd,&c,1);
	i++;
	}
	printf("%d",i);
}