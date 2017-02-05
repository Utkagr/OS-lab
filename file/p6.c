#include <stdio.h>
#include <fcntl.h>

main(){
	int fd1,fd2,i,j;
	char c,a[10],fn1[10],fn2[10];
	printf("Enter filename:");
	gets(fn1);
	printf("Enter filename:");
	gets(fn2);
	fd1 = open("xyz",O_WRONLY);
	fd2 = open("pqr",O_RDONLY);
	i=lseek(fd1,0,2);
	lseek(fd1,i,0);
	lseek(fd2,0,0);
	while(i=read(fd2,&c,1)){
		write(fd1,&c,1);
	}
}