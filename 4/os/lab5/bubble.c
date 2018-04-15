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
void main(){
	int a[1000000];
	for(int i=0;i<1000000;i++){
	a[i]=i;
	}
	bubble(a,1000000);
	printf("done");
}
