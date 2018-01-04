#include<stdio.h>
#include<string.h>
void main()
{	char a[100];
	printf("enter the string\n");
	scanf("%s",a);
	//fgets(a,100,stdin);
	int i,b,c;
	c=0;
	char d,e;
	b=strlen(a);
	printf("enter the character to be searched\n");

	scanf("%c",&e);
	scanf("%c",&d);
	printf("positions ");
	for(i=0;i<b;i++)
	{
		if(a[i]==d)
		{
			printf("%d ",i+1);
			c++;
		}
	}
	printf("occured %d times",c);
}