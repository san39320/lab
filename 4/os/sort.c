#include<stdio.h>
#define fr(a,n) for(int i=0;i<n;i++)
#define swap(a,b) ({int temp;temp=a;a=b;b=temp;})
void bubble(int *a,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
	}}}
}
void selection(int *a,int n){
	int min;
	for(int i=0;i<n-1;i++){min=i;
		for(int j=i+1;j<n;j++){
			if(a[min]>a[j]){min=j;}
		}
		swap(a[i],a[min]);
}}
//merege sort
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
			a[k]=R[j];j++;k++;}
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
		int a[5]={5,4,3,2,1};
		mergesort(a,0,4);
		fr(0,n)printf("%d ",a[i]);
}