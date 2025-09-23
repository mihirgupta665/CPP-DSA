/*
Input 1 :
5
A B C D E
2
X
Output 1 :
Updated list: A B X C D E 
*/

#include<iostream>
using namespace std;
struct node {
    char data;
    node* next;
};
node* create(char ch){
    node* newnode= new node;
    newnode->data=ch;
    newnode->next=nullptr;
    return newnode;
}
void insert(node** head,char ch,int pos){
    node* newnode=create(ch);
    node* current=*head;
    for(int i=0;i<pos;i++){
        if(current->next==nullptr){
            cout<<"Invalid position for insertion.";
            delete newnode;
            return;
        }
        current=current->next;
    }
    newnode->next=current->next;
    current->next=newnode;
}
void display(node* head){
    node* current=head->next;
    while(current!=nullptr){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
void deletenode(node* head){
    node* temp=head;
    while(temp!=nullptr);
    temp=temp->next;
    delete head;
    head=temp;
}
int main(){
    int n;
    cout<<"Enter the number of linked nodes : ";
    cin>>n;
    node* head= create('\0');
    for(int i=0;i<n;i++){
        char value;
        cout<<"Enter the "<<i+1<<"-node value : ";
        cin>>value;
        insert(&head,value,i);
    }
    int pos;
    char ch;
    cout<< "Enter the poition and element to be inserted : "<<endl;
    cin>>pos;
    cin>>ch;
    insert(&head,ch,pos);
    cout<<"Updated List : ";
    display(head);
    deletenode(head);
}