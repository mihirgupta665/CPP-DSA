/*
Input 1 :
1
3
1
5
1
9
2
3
0
Output 1 :
Customer ID 3 is enqueued
Customer ID 5 is enqueued
Customer ID 9 is enqueued
Dequeued customer ID: 3
Customer IDs in the queue are: 5 9 
Exiting program
*/

#include<iostream>
#define maxsize 20
using namespace std;
struct node{
    int data;
    node* next=nullptr;
};
struct queue {
    node* front;
    node* back;
    int size=0;
};
void initialize(queue* q){
    q->front=nullptr;
    q->back=nullptr;
}
bool isfull(queue* q){
    if(q->size == maxsize){
        return true;
    }
    return false;
}
bool isempty(queue* q){
    if(q->size==0){
        return true;
    }
    return false;
}
bool enqueue(queue* q, int ele){
    node* newnode= new node;
    newnode->data=ele;
    if(isfull(q)){
        cout<<"Queue overflow"<<endl;
        return false;
    }
    else if(isempty(q)){
        q->front=newnode;
        q->back=newnode;
        q->size++;
        return true;
    }
    else{
        q->back->next=newnode;
        q->back=q->back->next;
        q->size++;
        return true;
    }   
}
bool dequeue(queue* q,int &d){
    if(isempty(q)){
        cout<<"Queue underflow."<<endl;
        return false;
    }
    node* temp=q->front;
    d=temp->data;
    q->front=q->front->next;
    if(q->front==nullptr){
        q->back==nullptr;
    }
    delete temp;
    q->size--;
    return true;
}
void display(queue* q){
    if(isempty(q)){
        cout<<"Queue has no elements."<<endl;
        return;
    }
    cout<<"The Customer IDs in the queue are : ";
    node* current=q->front;
    while(current){
        cout<<current->data<<" ";
        current=current->next;
    }
    cout<<endl;
}
int main(){
    queue q;
    initialize(&q);
    int choice;
    while (true){
        cout<<"Enter choice between (0-3) : ";
        cin>>choice;
        switch(choice){
            case 0:
                cout<<"Exiting the program";
                exit(0);
            case 1:
                int value;
                cout<<"Enter a value to enqueue : ";
                cin>>value;
                if(enqueue(&q,value)){
                    cout<<"Customer ID "<<value<<" is enqueue."<<endl;
                }
                break;
            case 2:
                int de;
                if(dequeue(&q,de)){
                    cout<<"Customer ID "<<de<<" is dequeued."<<endl;
                }
                break;
            case 3:
                display(&q);
                break;
            default:
                cout<<"Invalid Choice!!! Enter a value between 0 to 3 only.";
                break; 
        }
    }
    return 0;
}