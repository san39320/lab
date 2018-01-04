#include<stdio.h>
void main()
{
	int a[100][100],i,j,m,n;
	printf("enter the number of rows and columns");
	scanf("%d %d",&m,&n);
	printf("enter the array elements");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i<j)
			{
				a[i][j]=0;
			}
		}
	}
		for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",a[i][j]);
		}
		printf("\n");
	}

}