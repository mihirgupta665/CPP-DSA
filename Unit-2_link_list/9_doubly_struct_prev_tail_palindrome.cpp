/*
Input 1 :
3
101
Pen
10
5.99
102
Notebook
20
12.99
103
Pencil
10 
1.99
101
Output 1 :
Item with ID 101 is present in the list.
*/
#include<iostream>
#include<string>
using namespace std;
struct Item {
    int id;
    string name;
    int q;
    double p;
};
struct node {
    Item item;
    node* next;
    node* prev;
    node(Item item){
        this->item=item;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
node* head=nullptr;
node* tail=nullptr;
void insertatend(Item item){
    node* newnode=new node(item);
    if(head==nullptr){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}
bool palindrone(){
    node* front=head;
    node* back=tail;
    while(front!=back && front->prev!=back){
        int q_front=front->item.q;
        int q_back=back->item.q;
        if(q_front!=q_back){
            return false;
        }
        front=front->next;
        back=back->prev;
    }
    return true; 
}
int main(){
    int n;
    cout<<"Enter the number of items in inventory : ";
    cin>>n;
    for(int i=0;i<n;i++){
        Item item;
        cout<<"Enter the ID of item of "<<i+1<<". : ";
        cin>>item.id;
        cout<<"Enter the Name of item of "<<i+1<<". : ";
        cin.ignore();
        getline(cin,item.name);
        cout<<"Enter the Quantity of item of "<<i+1<<". : ";
        cin>>item.q;
        cout<<"Enter the Price of item of "<<i+1<<". : ";
        cin>>item.p;
        insertatend(item);
    }
    if(palindrone()){
        cout<<"Yes its a palindromic Linked List"<<endl;
    }
    else{
        cout<<"No its not a palindromic Linked List"<<endl;
    }
    return 0;
}