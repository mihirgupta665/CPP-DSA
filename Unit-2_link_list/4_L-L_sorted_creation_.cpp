/*
Input 1 :
6
25 36 47 58 69 80
19
Output 1 :
Original data points: 25 36 47 58 69 80 
Updated data points: 19 25 36 47 58 69 80 
*/
#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
};
node* creation(int value){
    node* newnode= new node;
    newnode->data=value;
    newnode->next=nullptr;
    return newnode;
}
void insert(node** head, int val){
    node* newnode= creation(val);
    if(*head==nullptr || val<(*head)->data){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        node* current=*head;
        while(current->next!=nullptr && val>current->next->data){
            current=current->next;
        }
        if(current->next!=nullptr && current->next->data==val){
            return;
        }
        else{
            newnode->next=current->next;
            current->next=newnode;
        }
    }
}
void display(node* head){
    node* current=head;
    while(current){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    node* head=nullptr;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        insert(&head,val);
    }
    cout<<"Original data points : ";
    display(head);
    cout<<"Enter a new integer to be inserted : ";
    cin>>val;
    insert(&head,val);
    cout<<"Updated data points : ";
    display(head);
    return 0;
}