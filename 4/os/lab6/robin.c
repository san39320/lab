#include<stdio.h>
void main(){
	int n;int burst=0;
	printf("enter the number of process");
	scanf("%d",&n);
	int bt[n],ct[n];
	for(int i=0;i<n;i++){
	printf("enter the burst time %d AT %d",i+1,i);
	scanf("%d",&bt[i]);
	burst=burst+bt[i];
	}
	printf("enter the quantum time");
	int q;
	scanf("%d",&q);
	int flag=0;
	int time=0;
	while(burst!=0){
		for(int i=0;i<n;i++){
			if(bt[i]>=q){
			burst=burst-q;
			time=time+q;
			bt[i]=bt[i]-q;
				if(bt[i]==0){
				ct[i]=time;
				}
			}
			else if(bt[i]>0 && bt[i]<q){
			burst=burst-bt[i];
			time=time+bt[i];
			bt[i]=0;
			ct[i]=time;
			}
			printf("time:%d\n",time);
		}
	}
	for(int i=0;i<n;i++){
		printf("process %d %d \n",i,ct[i]);
	}
}