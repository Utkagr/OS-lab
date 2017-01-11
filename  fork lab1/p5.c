#include<stdio.h>
main(){
int i;
int p=getpid();
for(i=1;i<=5;i++)
    fork();
if(p==getapid(5))
    printf("A");
}
