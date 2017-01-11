#include<stdio.h>
main(){
printf("%d %d\n",getpid(),getppid()); //prints AL
int p = getpid();
fork();
if(p == getppid()) sleep(3);
printf("%d %d\n",getpid(),getppid());
sleep(2);
}
