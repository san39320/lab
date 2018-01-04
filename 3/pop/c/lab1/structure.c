#include<stdio.h>
struct student
{
	int regno;
	char name[20];
	int marks;


};
void main()
{   struct student a[2];
	int i;
	printf("enetr student deatails enter the regno ,name, marks\n");
	for(i=0;i<2;i++)
	{
	
		scanf("%d %s %d",&a[i].regno,a[i].name,&a[i].marks);


	}
	printf("student deatails are \n");
	for(i=0;i<2;i++)
	{
		printf("name=%s",a[i].name);
		printf("\tregno=%d",a[i].regno);
		printf("\tmarks=%d\n",a[i].marks);
	}
}