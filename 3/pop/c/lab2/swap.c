#include<stdio.h>
void main()
{	int n,a[100],i;
	printf("enter the size of array");
	scanf("%d",&n);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int small=a[1];
	 int big=a[2];
	 int ins=1;
	 int inb=2;
	 for(i=0;i<n;i++)
	 {
	 	if(a[i]<small)
	 	{
	 		small=a[i];
	 		ins=i;
	 	}
	 	if(a[i]>big)
	 	{
	 		big=a[i];
	 		inb=i;
	 	}
	 }
	 int temp;
	 temp=a[inb];
	 a[inb]=a[ins];
	 a[ins]=temp;
	 printf("manupulated array\n");
	 for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}


}