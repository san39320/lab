#include<stdio.h>
#define fr(a,n) for(int i=0;i<n;i++)
#define swap(a,b) ({int temp;temp=a;a=b;b=temp;})
void bubble(int *a,int start,int n){
	for(int i=start;i<n-1;i++){
		for(int j=start;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
	}}}
}
int rank(int *a,int start,int end,int r){
	int approx=approximatemedian(a,start,end);
	int q=partition(a,approx,start,end);
	if(r==q){
	return a[r];
	}
	else if(r<q){
	return rank(a,0,q-1,r);
	}
	else if((r>q) && (r<=end)){
	return rank(a,q+1,end,q-r);
}}
int approximatemedian(int *a,int start,int end){
	int d=(end-start)/5;
	int b[d];
	for(int i=0;i<d;i++){
			bubble(a,start+i*5,start+i*5+5);
			b[i]=a[(2*start+i*5+i*5+5)/2];
	}
	return rank(b,0,d-1,d/2);
}
int partition(int *a,int pivot,int low,int high){
	int x=pivot;int i=low-1;
	for(int j=low;j<high;j++)
		if(a[j]<=x){i++;swap(a[i],a[j]);}
	swap(a[i+1],a[high]);
	return(i+1);	
}

int main(){
	int a[5]={1,3,5,7,9};
	int ans=rank(a,0,5,3);
	printf("rank %d: %d",3,ans);
	return 1;
}
