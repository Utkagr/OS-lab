#include<stdio.h>
main(){
printf("%d %d\n",getpid(),getppid());
fork();
printf("%d %d\n",getpid(),getppid());
}
