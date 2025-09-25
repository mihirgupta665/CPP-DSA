/*
Input 1 :
abcdabcdeabcdabcdeabcdabcde
abcd
Output 1 :
Pattern found at index 0
Pattern found at index 4
Pattern found at index 9
Pattern found at index 13
Pattern found at index 18
Pattern found at index 22
*/

#include<iostream>
#include<string>
#include<deque>
using namespace std;
struct node {
    char data;
    node* next;
};
int main(){
    string str,p;
    cout<<"Enter the string : ";
    getline(cin,str);
    cout<<"Enter the pattern to be matched using sliding window : ";
    getline(cin,p);
    int n=str.length();
    int m=p.length();
    if(m>n){
        cout<<"Length of patter is bigger than the string."<<endl;
        return -1;
    }
    deque<char> dq(str.begin(),str.begin()+m);
    node* head=nullptr;
    node* rear=nullptr;
    for(int i=0;i<m;i++){
        node* newnode= new node;
        newnode->data=dq[i];
        newnode->next=nullptr;
        if(head==nullptr){
            head=newnode;
            rear=newnode;
        } 
        else{
            rear->next=newnode;
            rear=newnode;
        }
    }
    bool flag=false;
    string temp="";
    node* current=head;
    while(current!=nullptr){
        temp+=current->data;
        current=current->next;
    }
    if( temp==p){
        cout<<"Pattern found at index 0."<<endl;
        flag=true;
    }
    for(int i=m;i<n;i++){
        head=head->next;
        dq.pop_front();
        dq.push_back(str[i]);
        node* newnode= new node;
        newnode->data=str[i];
        newnode->next=nullptr;
        rear->next=newnode;
        rear=newnode;
        temp="";
        current=head;
        while(current!=nullptr){
            temp+=current->data;
            current=current->next;
        }
        if(temp==p){
            cout<<"Pattern fount at index "<<i-m+1<<endl;
            flag=true;
        }
    }
    if(!flag){
        cout<<"Pattern not found."<<endl;
        return -1;
    }
    return 0;
}