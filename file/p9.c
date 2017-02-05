#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
// int replace(int fd1,int fd2){
// 	char a,b;
// 	int i;
// 	read(fd1,&a,1);
// 	read(fd2,&b,1);
// 	i=lseek(fd2,-2,2);
// 	lseek(fd2,i,0);
// 	return fd2;
// }
main(){
	int fd1,fd2,i,j,k;
	char a='x',b='y',c;
	fd1=open("xyz",O_RDONLY);
	fd2=open("xyz",O_RDONLY);
//Set fd1 and fd2 at start and end
	i=lseek(fd1,0,0);
	j=lseek(fd2,-1,2);
	lseek(fd2,j,0);

	while(a!=b){
	//read leters
		read(fd1,&a,1);
		read(fd2,&b,1);
	//replace a with b
		i=lseek(fd1,-1,1);
		lseek(fd1,i,0);
		write(fd1,&b,1);
	//fd1 at req location and a replaced by b
	//replace b
	//check for loop break
		read(fd1,&c,1);
		k=lseek(fd1,-1,1);
		lseek(fd1,k,0);	
		k=lseek(fd2,-1,1);
		lseek(fd2,k,0);
		write(fd2,&a,1);
		k=lseek(fd2,-2,2);
		lseek(fd2,k,0);
		if(c==b)
			break;
	//b replaced and fd2 at position
	}
}