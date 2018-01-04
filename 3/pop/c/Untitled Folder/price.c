#include<stdio.h>

struct price
{
	int pen;
	int pencil;
	int eraser;
	int book;
	int penq;
	int pencilq;
	int eraserq;
	int bookq;
	int total;

};
void func(struct price *q)
{
	printf("enter the number of pens");
	scanf("%d",&q->penq);
	printf("enter the number of pencil");
	scanf("%d",&q->pencilq);
	printf("enter the number of eraser");
	scanf("%d",&q->eraserq);
	printf("enter the number of books");
	scanf("%d",&q->bookq);
	q->total=(q->penq)*(q->pen)+(q->pencilq)*(q->pencil)+(q->eraser)*(q->eraserq)+(q->bookq)*(q->book);
	printf("total price is %d",q->total);	

}
void main()
{	struct price s={5,10,2,60};
	struct price *p;
	p=&s;
	func(p);

}