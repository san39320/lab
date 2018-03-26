#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *left;
    Node *right;
    Node *parent;
    int code;
    char symbol;
    int frequency;
    Node(char s,int f){
        this->symbol=s;
        this->frequency=f;
        this->left=nullptr;
        this->right=nullptr;
        this->parent=nullptr;
    }
    Node(char s,int f,Node* parent,Node* left,Node* right){
        this->symbol=s;
        this->frequency=f;
        this->left=left;
        this->right=right;
        this->parent=parent;
    }
};
struct comparator{
    bool operator()(Node& i,Node& j){
        return i.frequency < j.frequency;
    }
};
vector<Node> nodes;
Node huffman(char symbols[],int frequency[]){
    for(int i=0;i<5;i++){
        nodes.push_back(Node(symbols[i],frequency[i]));
    }
    priority_queue<Node,vector<Node>,comparator> minheap;
    for(int i=0;i<nodes.size();i++){// creating and pushing into heap
        minheap.push(nodes[i]);
    }
    for(int i=1;i<=4;i++){
        Node leftnode=minheap.top();
        leftnode.code=1;
        cout<<leftnode.code;
        minheap.pop();
        Node rightnode=minheap.top();
        rightnode.code=0;
        minheap.pop();
        Node parent('p',leftnode.frequency+rightnode.frequency,NULL,&leftnode,&rightnode);
        leftnode.parent=&parent;
        rightnode.parent=&parent;
        minheap.push(parent);
    }
        
    return minheap.top();
    
}
void display(){
    for(int i=0;i<nodes.size();i++){
        Node* ptr=&nodes[i];
        cout<<ptr->symbol;
        while(ptr!=NULL){
            cout<<ptr->code<<"   ";
            ptr=ptr->parent;
        }
        cout<<"\n";
    }
}
int main(){
    int n=5;//number of symbols
    char symbols[5]={'a','b','c','d','e'};
    int frequency[5]={10,5,2,6,4};
    Node root=huffman(symbols,frequency);
    display();
    return 1; 
}
