/* 

Input 1 :
5
1 2 3 4 5
1
3
Output 1 :
Linked List before deletion: 1 2 3 4 5 
Linked List after deletion: 4 5 

*/

#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
void insert(node** head,int value){
    node* newnode=new node;
    newnode->data=value;
    newnode->next=nullptr;
    if(*head==nullptr){
        *head=newnode;
    }
    else{
        node* temp= *head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display(node* head){
    node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void deleterange(node** head,int s,int e){
    if(*head==nullptr){
        return;
    }
    node* temp=*head;
    node* prev=nullptr;
    for(int i=1;i<s && temp!=nullptr;i++){
        prev=temp;
        temp=temp->next;
    }
    for(int i=s;i<=e && temp!=nullptr;i++){
        node* nextnode=temp->next;
        delete temp;
        temp=nextnode;
    }
    if(prev!=nullptr){
        prev->next=temp;
    }
    else{
        *head=temp;
    }
}
void deletelist(node** head){
    node* temp=*head;
    while(temp){
        temp=temp->next;
        delete head;
        *head=temp;
    }
}
int main(){
    node* head=nullptr;
    int n;
    cout<<"Enter the number of nodes in the linked list : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int data;
        cout<<"Enter the value for " <<i+1<< " node : ";
        cin>>data;
        insert(&head,data);
    }
    int s,e;
    cout<<"Enter the starting and ending postion to delete : ";
    cin>>s>>e;
    cout<<"Linked List before deletetion : ";
    display(head);
    deleterange(&head,s,e);
    cout<<"Linked list after deletetion : ";
    if(head==nullptr){
        cout<<"All the nodes were deleted.";
    }
    else{
        display(head);
    }
    deletelist(&head);
    return 0;
}
