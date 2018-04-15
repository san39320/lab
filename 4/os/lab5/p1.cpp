#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
#define left(i)({return(2*i+1);})
#define right(i)({return(2*i+2);})
#define parent(i)({return((i+1)/2-1);})
#define fr(a,n) for(int i=a;i<n;i++)
const int unoccupied=-1;
const int split=-2;
const int memory=1024;
const int blocksize=64;
int size;
int maxorder;
int levels;
int mem[100];
void initialize(){
	maxorder=(log(memory/blocksize)/log(2));
	levels=maxorder+1;
	size=(pow(2,levels)-1);
	memset(mem,-1,size*4);
}
void allocate(int process){
	int noofblocksreq=process/blocksize;
	int level=16/
}
int main(){
	initialize();
	int process[5]={63,64,128,32,200}
	fr(0,5)allocate(process[i]);
	return 1;
}