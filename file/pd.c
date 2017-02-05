#include <stdio.h>
#include <fcntl.h>
main(){
	int fd,i;
	char a[10],fn[10];
	fd=open("xyz",O_RDWR);
	i=lseek(fd,-4,2);
	lseek(fd,i,0);
	read(fd,a,3);
	lseek(fd,0,0);
	write(fd,a,3);
}