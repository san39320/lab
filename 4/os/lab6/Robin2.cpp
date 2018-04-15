#include <iostream>
#include <queue>
#include<stdio.h>
 
using namespace std;
queue <int> q;
 
void showq()
{
    while (!q.empty())
    {
        cout << "yes its empty";
    }
    q.push(10);
    cout<<q.front();
    q.push(20);
    cout<<q.back();
//
    printf("\nss");
}
 
int main()
{
    showq();
    return 1;   
}
