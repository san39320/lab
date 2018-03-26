#include<stdio.h>
int counter(int* a,int l,int r,int element){
	int count=0;
	for(int i=l;i<r+1;i++){
	if(a[i]==element){
		count++;
	}
	}
	if(count==0){
	return -1;
	}
	return count;
}
int majority(int* a,int l,int r){
	if(l==r){
	return a[l];
	}else
	if((l-r)==1){
		if(a[l]==a[r]){
		return a[l];
		}
		else{
		return -1;
		}
	}
	else if(l<r){
		int m=(r+l)/2;
		int left,right,countleft,countright;
		left=majority(a,l,m);
		right=majority(a,m+1,r);
		if(left!=-1){
			countleft=counter(a,l,r,left);
		}else if(right != -1){
			countright=counter(a,l,r,right);
		}
		if(countleft>m)
			{return left;}
		else if(countright>m)
			{return right;}
		return -1;
	}
}

int main(){
	int a[10]={1,2,1,1,2,4,1,1,1,8};
	int result=majority(a,0,9);
	if(result!=-1){
	printf("the majority element is %d",result);
	}
	else{
	printf("no majority element");
	}
	return 1;
}
