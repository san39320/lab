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
int approximatemedian(int *a,int n){
	int d=n/5;
	int b[d];
	for(int i=0;i<d;i++){
			bubble(a,i*5,i*5+5);
			b[i]=a[(i*5+i*5+5)/2];
	}
	return 1;
	//return rank(d,d/2);
}
int rank(int *a,int n,int r){
	int approx=approximatemedian(a,n);
	return 1;
}
int main(){
	int a[5]={1,3,5,7,9};
	int ans=rank(a,5,3);
	printf("rank %d: %d",3,ans);
	return 1;
}