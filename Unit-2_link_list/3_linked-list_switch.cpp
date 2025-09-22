/*
Input 1 :
1 10
2 20
3
4
Output 1 :
Linked List: 10 20
*/
#include<iostream>
using namespace std;
struct node{
    int value;
    node* next;
};
void appendleft(node** head,int val){
    node* newnode=new node;
    newnode->value=val;
    newnode->next=*head;
   *head=newnode; 
}
void appendright(node** head, int val){
    node* newnode=new node;
    newnode->value=val;
    newnode->next=nullptr;
    if(*head==nullptr){
        *head=newnode;
    }
    else{
        node* current= *head;
        while(current->next){
            current=current->next;
        }
        current->next=newnode;
    }
}
void display(node* head){
    node* current= head;
    cout<<"Linked list : ";
    while(current){
        cout<<current->value<<" ";
        current=current->next;
    }
    cout<<endl;
}
int main(){
    node* head= nullptr;
    int choice;
    int val;
    do{
        cout<<"Enter the choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                cin>>val;
                appendleft(&head,val);
                break;
            case 2:
                cin>>val;
                appendright(&head,val);
                break;
            case 3:
                display(head);
                break;
            case 4:
                break;
            default:
                cout<<"Invalid Choice."<<endl;
        }
    }while(choice!=4);
    return 0;
}