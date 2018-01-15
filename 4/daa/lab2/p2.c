#include<stdio.h>
int findpeak(int *a,int start,int end){
	int mid;
	if(start<=end){
		mid=(start+end)/2;
		if(a[mid-1]<a[mid]&&a[mid]>a[mid+1]){
			return(a[mid]);
		}else if(a[mid-1]<a[mid]&&a[mid]<a[mid+1]){
			return(findpeak(a,mid,end));
		}else 
			return(findpeak(a,start,mid));
	}
	return(-10);
}
int main(){
	printf("enter the number of elements");
	int n;
	scanf("%d",&n);
	printf("enter the elements\n");
	int a[n];;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(findpeak(a,0,n-1)==-100)
		printf("no peak");
	else
		printf("answer is:%d\n",findpeak(a,0,n-1));
	return 1;
}