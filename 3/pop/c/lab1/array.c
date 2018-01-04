#include<stdio.h>
void main()
{
	int i,a[10];
	printf("insert array elements \n");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("adress values of array are \n");
	for(i=0;i<10;i++)
	{
		printf("%pn \t",a
			+i);
	}
}