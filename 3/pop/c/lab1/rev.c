#include<stdio.h>
void main()
{
	
	int *a;
	int b;
	a=&b;
	printf("enter the number \n");
	scanf("%d",&b);
	int c=0;
	while(*a!=0)
	{
		c=c*10+*a%10;
		*a=*a/10;

	}
	printf("reverse of number is %d",c);

}