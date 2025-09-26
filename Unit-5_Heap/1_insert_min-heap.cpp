/*
7
1 2 3 4 5 6 10
Output 3 :
1 is not a multiple of five
2 is not a multiple of five
3 is not a multiple of five
4 is not a multiple of five
6 is not a multiple of five
5 10 
*/
#include<iostream>
#include<vector>
using namespace std;
void insert(vector<int> &heap, int data, int &size){
    size++;
    int i=size-1;
    heap[i]=data;
    while(i>0 && heap[(i-1)/2]>heap[i]){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
void print(vector<int> &heap, int n){
    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cout<<"Enter the number of elements in the heap : ";
    cin>>n;
    int size=0;
    vector<int> heap(n);
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        if(data%5==0){
            insert(heap,data,size);
        }
    }
    print(heap,size);
    return 0;
}