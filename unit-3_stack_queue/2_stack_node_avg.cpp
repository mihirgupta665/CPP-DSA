/*
Input 2 :
6
23 78 94 27 19 74
Output 2 :
Initial Stack: 74 19 27 94 78 23 
Average: 52.50
Popped Value: 74
Updated Average: 48.20
*/

#include<iostream>
#include<iomanip>
#define maxsize 10
using namespace std;
struct node {
    int data;
    int sum;
};
struct stack {
    node arraystack[maxsize];
    int top;
    int size;
};
void init(stack* s){
    s->top=-1;
    s->size=0;
}
void push(stack* s, int e){
    if(s->top>=maxsize-1){
        cout<<"Stack overflow"<<endl;
        return;
    }
    s->top++;
    s->arraystack[s->top].data=e;
    s->arraystack[s->top].sum= (s->top==0)?e:s->arraystack[s->top-1].sum + e;
    s->size++;
}
void printstack(stack* s){
    if(s->top<0){
        cout<<"No element in Stack"<<endl;
        return ;
    }
    for(int i=s->top;i>=0;i--){
        cout<<s->arraystack[i].data<<" ";
    }
    cout<<endl;
}
float avgvalue(stack* s){
    if(s->size==0){
        return -1.00;
    }
    return (float)s->arraystack[s->top].sum/s->size;
}
int popout(stack* s){
    if(s->size==0){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    int x=s->arraystack[s->top].data;
    s->top--;
    s->size--;
    return x;
}
int main(){
    stack s;
    init(&s);
    int num;
    cout<<"Enter the number of elements in the stacks : ";
    cin>>num;
    for(int i=0;i<num;i++){
        int ele;
        cout<<"Enter the "<<i+1<<". number in  the stack : ";
        cin>>ele;
        push(&s,ele);
    }
    cout<<"Initial stack : ";
    printstack(&s);
    float avg1= avgvalue(&s);
    if(avg1!=-1.00){
    cout<<"Average before popping : "<<fixed<<setprecision(2)<<avg1<<endl;
    }
    int pop=popout(&s);
    if(pop!=-1){
        cout<<"The popped value : "<<pop<<endl;
    }
    cout<<"Final Stack : ";
    printstack(&s);
    float avg2= avgvalue(&s);
    if(avg2!=-1.00){
    cout<<"Average before popping : "<<fixed<<setprecision(2)<<avg2<<endl;
    }
    return 0;
}