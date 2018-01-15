#include<stdio.h>
int main(){
int a[5]={1,3,9,8,5};
int sum=0;int n=5;
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		if(a[i]<a[j]){
			sum=sum+1;
		}
	}}
	printf("%d",sum);

}