#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

void main(){
	int choice,c1=1,c2=1,turn=1;
	printf("Enter 1 for process 1 to start.");
	printf("Enter 2 for process 2 to start.");
	printf("Enter 3 for both prrocess to start.");
	cin>>choice;
	if(choice == 1){
		c1=0;
		while(c2==0){

		}
		cout<<"Process p1 enters the critical region"<<endl;
		c1=1;
		turn=2;
		
	}	
}