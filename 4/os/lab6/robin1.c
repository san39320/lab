#include<stdio.h>
#include<stdlib.h>
//circular queue
int n;
int front =  - 1;
int rear =  - 1;
//circular queue operation
void insertq(int *arr,int value)
{
    if ((front == 0 && rear == n-1) ||
        (rear == front-1))
    {
        printf("\nQueue is Full");
        return;
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == n-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
void deleteq(int* arr)
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == n-1)
        front = 0;
    else
        front++;
    
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
	while(burst>0) {
        if (front != -1) {
            int i = circular[front];

            if (bt[i] >= q) {
                burst = burst - q;
                time = time + q;
                bt[i] = bt[i] - q;
                deleteq(circular);
                if (bt[i] == 0) {
                    ct[i] = time;
                } else {
                    insertq(circular, i);
                }
            } else if (bt[i] > 0 && bt[i] < q) {
                deleteq(circular);
                burst = burst - bt[i];
                time = time + bt[i];
                bt[i] = 0;
                ct[i] = time;
            }
            printf("time:%d\n", time);
        }

        //adding arrieved process to queue
        for (int i = arrivalcounter + 1; i < n; i++) {
            if (at[i] > time && front == -1) {
                arrivalcounter++;
                time = at[arrivalcounter];
                insertq(circular, arrivalcounter);
            } else if (at[i] > time) { break; }
            else if (at[i] <= time) {
                arrivalcounter++;
                insertq(circular, arrivalcounter);
            }
        }
    }

	for(int i=0;i<n;i++){
		printf("process %d %d \n",i,ct[i]);
	}
}
