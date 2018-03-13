#include<stdio.h>
#define fr(a,n) for(int i=a;i<n;i++)
void merge(int* a,int *b,int l,int m,int r){
	int n1=m-l+1,n2=r-m,i,j,k;
	int LA[n1],RA[n2],LB[n1],RB[n2];
	for(int i=0;i<n1;i++)LA[i]=a[l+i];
	for(int i=0;i<n2;i++)RA[i]=a[m+1+i];
	for(int i=0;i<n1;i++)LB[i]=b[l+i];
	for(int i=0;i<n2;i++)RB[i]=b[m+1+i];
	i=0;j=0;k=l;	
	while((i<n1)&&(j<n2)){
		if(LA[i]<=RA[j]){
			a[k]=LA[i];b[k]=LB[i];i++;k++;
		}else{
			a[k]=RA[j];b[k]=RB[j];j++;k++;}
	}
	while(i<n1){a[k]=LA[i];b[k]=LB[i];i++;k++;}
	while(j<n2){a[k]=RA[j];b[k]=RB[j];j++;k++;}
}
void mergesort(int* a,int *b,int l,int r){
	if(l<r){
	int m=(l+r)/2;
	mergesort(a,b,l,m);
	mergesort(a,b,m+1,r);
	merge(a,b,l,m,r);}
}
void displayinterval(int *start,int *finish,int n){
    int counter=0;
    int resource=0;
    int flag[n];memset(flag,0,n);
    while(counter!=n){
        resource++;int prev=0;
        printf("resource %d",resource);
	    for(int i=0;i<n;i++){
		    if((flag[i]==0) && (start[i]>=prev)){
			    printf("event : %d %d",start[i],finish[i]);
                flag[i]=1;
			    prev=finish[i];
                counter++;
		    }		
	    }
    }
}
void main(){
 	int n,t;
 	printf("enter the number of events\n");
 	scanf("%d",&n);
 	int start[n],finish[n];
	printf("enter start and end values\n");
	for(int i=0;i<n;i++){
		scanf("%d %d",&start[i],&finish[i]);
	}
 	mergesort(finish,start,0,n-1);
	fr(0,n)printf("%d",start[i]);
 	displayinterval(start,finish,n); 
}
