#include<stdio.h>
main(){
int p=getpid();
fork();
if(p==getpid()) printf("X");
if(p==getppid()) printf("Y");
sleep(1);
}
