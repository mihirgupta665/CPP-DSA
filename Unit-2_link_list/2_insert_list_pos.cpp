/*
Input 2 :
3
Emma
Daniel
Sophia
Charlotte 1
Output 2 :
Charlotte Emma Daniel Sophia 
*/

#include<iostream>
#include<string>
using namespace std;
struct node{
    string data;
    node* next;  
};
node* creation(const string& data){
    node* newnode= new node();
    newnode->data=data;
    newnode->next=nullptr;
    return newnode;
}
void insert(node** head,const string& data,int pos){
    node* newnode=creation(data);
    if(pos==1){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        node* temp=*head;
        for(int i=1;i<pos-1 && temp!=nullptr;i++){
            temp=temp->next;
        }
        if(temp==nullptr){
            node* lastnode=*head;
            while(lastnode->next){
                lastnode=lastnode->next;
            }
            lastnode->next=newnode;
        }
        else{
            newnode->next=temp->next;
            temp->next=newnode;
        }          
    }
}
void display(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    int n;
    cout<<"Enter the number of string : ";
    cin>>n;
    node* head= nullptr;
    string data;
    for(int i=1;i<=n;i++){   
        cin>>data;
        insert(&head,data,i);
    }
    int pos;
    cin>>data>>pos;
    insert(&head,data,pos);
    display(head);
    return 0;
}