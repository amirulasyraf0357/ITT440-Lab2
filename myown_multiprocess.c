#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void child(){

	char name[20];
	printf("Enter your name: ");
	fgets(name, 20, stdin);
	printf("Your name is %s ", name);
	exit(0);
}

void parent(){

	printf("\nWaiting for child process..\n  ");
	wait(NULL);
	printf("CHILD PROCESS FINISH! \n");
}


int main(void){

for(int i = 0; i<4; i++){
int pid = fork();

if(pid == 0){
	child();
}

else if(pid > 0){
	parent();
}

else {
    printf("Cannot create child process");
  }

}
return(0);

}
