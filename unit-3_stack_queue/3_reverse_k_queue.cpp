/*
Input 1 :
8
3
101 102 103 104 105 106 107 108
Output 1 :
103 102 101 104 105 106 107 108 
Input 2 :
4
2
12 43 58 75
Output 2 :
43 12 58 75 
*/

#include<iostream>
using namespace std;
struct queue {
    int* arr;
    int front=-1;
    int back=-1;
    int capacity;
    int size=0;
    queue(int capacity){
        this->capacity=capacity;
        arr=new int[capacity];
    }
    void enqueue(int ele){
        if(size==capacity){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if(front==-1){
            front++;
            back++;
            arr[back]=ele;
            size++;
            return;  
        }
        back++;
        arr[back]=ele;
        size++;
    }
    int dequeue(){
        if(size==0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        int x=arr[front];
        front++;
        size--;
        return x;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
void k_reverse(queue &q,int k){
    if(k==0){
        return;
    }
    int x=q.dequeue();
    k_reverse(q,k-1);
    q.enqueue(x);
}
void solve(queue &q, int z){
    while(z){
        int x=q.dequeue();
        q.enqueue(x);
        z--;
    }
}
int main(){
    int num;
    cout<<"Enter the number of elements of the queue : ";
    cin>>num;
    int k;
    cout<<"Enter the front elements to reverse : ";
    cin>>k;
    queue q(num);
    for(int i=0;i<num;i++){
        int value;
        cout<<"Enter the value of "<<i+1<<". number of queue : ";
        cin>>value;
        q.enqueue(value);
    }
    k_reverse(q,k);
    solve(q,q.size-k);
    q.display();
    return 0;
}