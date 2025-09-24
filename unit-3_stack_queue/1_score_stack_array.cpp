/*
Input 2 :
1 2
1 4
6
2
2
2
3
4
5
Output 2 :
Invalid choice
Stack is empty
Maximum element: -1
Stack is empty
*/
#include<iostream>
#define size 10
using namespace std;
int top=-1;
int maxtop=-1;
int mainstack[size];
int maxstack[size];
void push(int ele){
    if(top>=size-1){
        return;
    }
    top++;
    mainstack[top]=ele;
    if(maxtop==-1 || ele>maxstack[maxtop]){
        maxtop++;
        maxstack[maxtop]=ele;
    }
    return;
}
void pop(){
    if(top<0){
        cout<<"stack underflow"<<endl;
        return;
    }
    int x=mainstack[top];
    top--;
    if(x==maxstack[maxtop]){
        maxtop--;
    }
    return;
}
void maxelement(){
    if(maxtop<0){
        cout<<"No element found."<<endl;;
        return;
    }
    cout<<"Max element : "<<maxstack[maxtop]<<endl;
}
void getstack(int* stack){
    if(top<0){
        cout<<"Nothing in the stack"<<endl;
        return;
    }
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
    cout<<endl;
    return;
}
int main(){
    int choice;
    while(true){
        cout<<"Enter the choice : ";
        cin>>choice;
        switch(choice){
            case 1:
            int ele;
            cout<<"Enter the element to pust to stacks : ";
            cin>>ele;
            push(ele);
            break;
            case 2:
            pop();
            break;
            case 3:
            maxelement();
            break;
            case 4:
            getstack(mainstack);
            break;
            case 5:
            cout<<"Exiting the program. Goodbye!!!"<<endl;;
            exit(0);
            default: 
            cout<<"Invalid choice. Enter between 1 to 5"<<endl;
        }
    }
    return 0;
}