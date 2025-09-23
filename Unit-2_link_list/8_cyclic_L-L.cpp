/*
Input 1 :
3
10 20 30
2
40 50
Output 1 :
Number of nodes in the CLL is 5
30 20 10 40 50 
*/

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* link;
};
typedef Node* node;
node getnode(){
    node newnode=new Node;
    return newnode;
}
void insertathead(node head,int value){
    node newnode=getnode();
    newnode->data=value;
    if(head==head->link){
        head->link=newnode;
        newnode->link=newnode;
    }
    else{
        node current=head->link;
        while(current->link!=head->link){
            current=current->link;
        }
        current->link=newnode;
        newnode->link=head->link;
        head->link=newnode;
    }
    head->data++;
}
void insertattail(node head,int value){
    node newnode=getnode();
    newnode->data=value;
    if(head->link->link==head->link){
        newnode->link=head->link->link;
        head->link->link=newnode;
    }
    else{
        node current=head->link;
        while(current->link!=head->link){
            current=current->link;
        }
        newnode->link=current->link;
        current->link=newnode;
    }
    head->data++;
}
void display(node head){
    if(head->link==head){
        cout<<"Number of nodes in CLL is : "<<head->data<<endl;
        return;
    }
    cout<<"Number of nodes in CLL is : "<<head->data<<endl;
    node current=head->link;
    do{
        cout<<current->data<<" -> ";
        current=current->link;
    }while(head->link!=current);
    cout<<" repeat "<<endl;
}
int main(){
    node head=nullptr;
    head=getnode();
    head->data=0;
    head->link=head;
    int n;
    cout<<"Enter the number of elements to be inserted at head : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int value;
        cout<<"Enter a value to inserted at head : ";
        cin>>value;
        insertathead(head,value);
    }
    int m;
    cout<<"Enter the number of elements to be inserted at the Tail : ";
    cin>>m;
    for(int i=0;i<m;i++){
        int value;
        cout<<"Enter the value to be inserted at tail : ";
        cin>>value;
        insertattail(head,value);
    }
    display(head);
    return 0;
}