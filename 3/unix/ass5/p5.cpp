#include<stdio.h>
#include<unistd.h>
int createfork(int i)
{
	int z=1;
	pid_t pid;

while(z<=i+1){
	pid=fork();
	if( pid == 0 )
	{
		return 0;
	}else if( pid > 0)
	{
		z=z+1;
		
	}
}
return 2;
}
int main()
{
	pid_t pid;
	int i;
	pid = createfork(2);			

	if(pid==0)
	{	printf("i am child process with pid %d \n",pid);
		
		
	}
	else
	{
		printf("I am Parent process\n");
	}
return(0);
}
