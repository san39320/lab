#include<stdio.h>
#include<string.h>
void swap1(int a,int b);
void swap2(int *a,int *b);

int main()
{
int a,b;
printf("enter two numbers\n");
scanf("%d%d",&a,&b);
swap1(a,b);
printf("using call by value at main a=%d b=%d \n",a,b);
swap2(&a,&b);
printf("using call by reference at main a=%d b=%d \n",a,b);
return 0;
}
void swap1(int a,int b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	printf("value at value function a=%d b=%d \n",a,b);

}
void swap2(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
    printf("value at reference function a=%d b=%d \n",*a,*b);
}