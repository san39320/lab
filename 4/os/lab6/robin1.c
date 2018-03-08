#include<stdio.h>
#include<stdlib.h>
//circular queue
int n;
int front =  - 1;
int rear =  - 1;
void insertq(int queue[], int item)
{
    if ((front == 0 && rear == n - 1) || (front == rear + 1))
    {
        printf("queue is full");
        return;
    }
    else if (rear ==  - 1)
    {
        rear++;
        front++;
    }
    else if (rear == n - 1 && front > 0)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = item;
}

void display(int queue[])
{
    int i;
    printf("\n");
    if (front > rear)
    {
        for (i = front; i < n; i++)
        {
            printf("%d ", queue[i]);
        }
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
}

void deleteq(int queue[])
{
    if (front ==  - 1)
    {
        printf("Queue is empty ");
    }
    else if (front == rear)
    {
        printf("\n %d deleted", queue[front]);
        front =  - 1;
        rear =  - 1;
    }
    else
    {
        printf("\n %d deleted", queue[front]);
        front++;
    }
}

//circular queue


void main(){
	int burst=0;
	printf("enter the number of process");
	scanf("%d",&n);
	int bt[n],ct[n],at[n];
	for(int i=0;i<n;i++){
		//assuming at is sorted
		printf("enter the arrival time and burst time of process %d",i+1);
		scanf("%d",&bt[i]);
		at[i]=i;
		burst=burst+bt[i];
	}
	printf("enter the quantum time");
	int q;
	scanf("%d",&q);
	int flag=0;
	//initializing to first process
	int time=at[0];
	int arrivalcounter=0;
	int circular[n];insertq(circular,0);
	while(burst>0){
		if(front!=-1){
			int i=circular[front];

			if(bt[i]>=q){
			burst=burst-q;
			time=time+q;
			bt[i]=bt[i]-q;
			deleteq(circular);
				if(bt[i]==0){
				ct[i]=time;
				}else{
				insertq(circular,i);
				}
			}
			else if(bt[i]>0 && bt[i]<q){
			deleteq(circular);
			burst=burst-bt[i];
			time=time+bt[i];
			bt[i]=0;
			ct[i]=time;
			}
			printf("time:%d\n",time);
		}else if(front==-1){
			if(arrivalcounter<n){
				arrivalcounter++;
				time=at[arrivalcounter+1];
			}
		}
		//adding arrieved process to queue
		for(int i=arrivalcounter+1;i<n;i++){
			if(at[arrivalcounter]>time && front==-1){
				arrivalcounter++;
				insertq(circular,arrivalcounter);
			}
			else if(at[arrivalcounter]>time){break;}
			else if(at[arrivalcounter]<time){				
				arrivalcounter++;
				insertq(circular,arrivalcounter);}
		}

	}
	for(int i=0;i<n;i++){
		printf("process %d %d \n",i,ct[i]);
	}
}