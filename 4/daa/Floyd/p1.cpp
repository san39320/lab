#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=6;
    int** graph=(int **)malloc(7*sizeof(int *));
    int** prev=(int **)malloc(7*sizeof(int *));
    int** next=(int **)malloc(7*sizeof(int *));
    for(int i=0;i<7;i++){
        graph[i]=(int *) malloc(7*sizeof(int));
        prev[i]=(int *) malloc(7*sizeof(int));
        next[i]=(int *) malloc(7*sizeof(int));
    }
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            if(i==j){
            graph[i][j]=0;
            prev[i][j]=0;
            }
            else{
            graph[i][j]=1000;
            prev[i][j]=1000;}
        }
    }
    graph[4][1]=-4;graph[2][1]=1;graph[3][2]=2;graph[2][4]=2;graph[1][5]=-1;graph[6][2]=5;graph[3][6]=-8;graph[6][3]=10;graph[5][2]=7;graph[4][5]=3;
    prev[4][1]=-4;prev[2][1]=1;prev[3][2]=2;prev[2][4]=2;prev[1][5]=-1;prev[6][2]=5;prev[3][6]=-8;prev[6][3]=10;prev[5][2]=7;prev[4][5]=3;
    //floyd
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                next[i][j]=min(prev[i][j],prev[i][k]+prev[k][j]);
            }
            prev=next;
        }
    }
    cout<<"graph is\n";
    for(int i=1;i<7;i++){
        for(int j=1;j<7;j++){
            cout<<"\t"<<graph[i][j];
        }
        cout<<"\n";
    }
    cout<<"min distance\n";
    for(int i=1;i<7;i++){
        for(int j=1;j<7;j++){
            cout<<"\t"<<prev[i][j];
        }
        cout<<"\n";
    }
    return 1;
}