/*
Input 3 :
! @ # % ^ % # @ ! $
Output 3 :
The linked list is a palindrome
*/
#include<iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
node* reverse(node* slow){
    node* prev=nullptr;
    node* curr=slow;
    while(curr!=nullptr){
        node* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
bool palindrone(node* head){
    if(head == nullptr || head->next == nullptr){
        return true;
    }
    node* slow=head;
    node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    node* secondhalf = reverse(slow); 
    node* firsthalf = head;
    while(secondhalf!=nullptr){
        if(secondhalf->data!=firsthalf->data){
            return false;
        }
        secondhalf=secondhalf->next;
        firsthalf=firsthalf->next;
    }
    return true;
}
node* create(){
    node* head= nullptr;
    node* tail= nullptr;
    char ch;
    while(true){
        cout<<"Enter a character for the linked-list : ";
        cin>>ch;
        if(ch=='$'){
            break;
        }
        node* newnode=new node;
        newnode->data=ch;
        newnode->next=nullptr;
        if(head==nullptr){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    return head;
}
int main(){
    node* head= create();
    bool check= palindrone(head); 
    if(check){
        cout<<"The linked-list is a palindrone";
    }
    else{
        cout<<"The linked-list is not a plaindrone.";
    }
    return 0;
}
