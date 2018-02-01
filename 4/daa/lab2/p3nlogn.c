#include<stdio.h>
#define fr(a,n) for(int i=0;i<n;i++)
#define swap(a,b) ({int temp;temp=a;a=b;b=temp;})
int sum=0;
void merge(int* a,int l,int m,int r){
	int n1=m-l+1,n2=r-m,i,j,k;
	int L[n1],R[n2];
	for(int i=0;i<n1;i++)L[i]=a[l+i];
	for(int i=0;i<n2;i++)R[i]=a[m+1+i];
	i=0;j=0;k=l;	
	while((i<n1)&&(j<n2)){
		if(L[i]<=R[j]){
			a[k]=L[i];i++;k++;
		}else{
			a[k]=R[j];j++;k++;
			sum=sum+(n1)-i;
			//printf("%d",sum);
		}
	}
	while(i<n1){a[k]=L[i];i++;k++;}
	while(j<n2){a[k]=R[j];j++;k++;}
}
void mergesort(int* a,int l,int r){
	if(l<r){
	int m=(l+r)/2;
	mergesort(a,l,m);
	mergesort(a,m+1,r);
	merge(a,l,m,r);}
}
void main(){
		int n=5;
		int a[5]={1,2,5,3,4};
		mergesort(a,0,4);
		fr(0,n)printf("%d ",a[i]);
		printf("\n%d",sum);
}