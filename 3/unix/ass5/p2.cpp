#include<stdio.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	int i;
	pid = fork();			
	if(pid == -1)
	{
		printf("Error making Process!\n");
		return(-1);
	}
	if(pid==0)
	{	
		
		printf("i am child process with pid %d",pid);
		for(i=0;i<1000;i++){
			printf("%d",i%10);
			if(i%10==0){
				printf("%c",'\n');
			}
		}
		
	}
	else
	{
		printf("I am Parent process with pid %d\n",pid);
		for(i=0;i<1000;i++){
			printf("%d",i%10);
			if(i%10==0){
				printf("%c",'\n');
			}
		}
		
	}
return(0);
}
