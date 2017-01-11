#include<stdio.h>
main(){
int i;
for(i=1;i<3;i++){
printf("X\n");
fork();
printf("Y\n");
}
}
