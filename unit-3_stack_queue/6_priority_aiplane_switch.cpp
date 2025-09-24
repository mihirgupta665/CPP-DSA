/*
Input 5 :
1
AA123
8
200.50
1
BA456
10
300.75
1
DL789
9
250.64
2
2
2
4
Output 5 :
Flight added to the system.
Flight added to the system.
Flight added to the system.
Booked ticket for flight: AA123
Booked ticket for flight: DL789
Booked ticket for flight: BA456
Exiting the application.
*/

#include<iostream>
#include<string>
#define maxsize 100
using namespace std;
struct flight{
    string name;
    int time;
    double price;
};
struct priorityqueue{
    int size;
    flight* arr[maxsize];
};
void initialize(priorityqueue* qn){
    qn->size=0;
}
bool isempty(priorityqueue* qn){
    return qn->size==0;
}
bool is_full(priorityqueue* qn){
    return qn->size==maxsize;
}
bool enqueue(priorityqueue* qn){
    if(is_full(qn)){
        cout<<"PriorityQueue Overflow"<<endl;
        return false;
    }
    cout<<"Enter the details of the Flight  "<<qn->size+1<<" : "<<endl;
    string str;
    cout<<"Enter the name of Flight : ";
    cin.ignore();
    getline(cin,str);
    int t;
    cout<<"Enter the departure time for the flight  : ";
    cin>>t;
    double p;
    cout<<"Enter the price for the Flight ticket : ";
    cin>>p;
    flight* airplane=new flight;
    airplane->name=str;
    airplane->time=t;
    airplane->price=p;
    int i=qn->size-1;
    for(i=qn->size-1;i>=0;i--){
        if(qn->arr[i]->time>t || (qn->arr[i]->time==t && qn->arr[i]->price<p)){
            qn->arr[i+1]=qn->arr[i];
        }
        else{
            break;
        }
    }
    qn->arr[i+1]=airplane;
    qn->size++;
    cout<<"Flight "<<airplane->name<<" has been added to the system."<<endl;
    return true;
}
bool book_dequeue(priorityqueue* qn){
    if(isempty(qn)){
        cout<<"No Tickets available to be booked."<<endl;
        return false;
    }
    cout<<"Booked tickets for the Flight : "<<qn->arr[0]->name<<endl;
    delete qn->arr[0];
    for(int i=0;i<qn->size;i++){
        qn->arr[i]=qn->arr[i+1];
    }
    qn->size--;
    return true;
}
void checkticket(priorityqueue* qn){
    if(isempty(qn)){
        cout<<"No  tickets available."<<endl;
        return;
    }
    cout<<"Next Flight : "<<qn->arr[0]->name<<endl;
    return;
}
int main(){
    priorityqueue queue;
    initialize(&queue);
    while(true){
        int choice;
        cout<<"Enter your choice (1-4) : ";
        cin>>choice;
        switch(choice){
            case 1:
            enqueue(&queue);
            break;
            case 2:
            book_dequeue(&queue);
            break;
            case 3:
            checkticket(&queue);
            break;
            case 4:
            cout<<"Exiting the Flight Application. GoodBye!!!";
            exit(0);
            break;
            default:
            cout<<"Enter a number between 1 to 4 only"<<endl;
            break;
        }
    }
    return 0;
}
