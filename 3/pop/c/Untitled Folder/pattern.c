#include<stdio.h>
void main()
{
	int i,j,k,l,m;
	l=1;
	m=0;
	for(i=1;i<=9;i++)
	{
		if(i==1||i==9)
		{
			for(j=0;j<=5;j++)
				printf(" ");
			printf("1");
		}
		if((i<=5)&&(i>1))
		{
			for(j=7;j>i;j--)
				printf(" ");
			
			for(k=1;k<=i+l;k++)
				printf("%d",k);
			l++;
		}
  		if((i>5)&&(i<9))
		{
            for(j=4;j<=i;j++)
            {
            	printf(" ");
            } 
            for(j=1;j<=(i+1-m);j++)
            {
            	printf("%d",j);
            }
            m=m+3;
	   	} 
	   	printf("\n");
	}
}
