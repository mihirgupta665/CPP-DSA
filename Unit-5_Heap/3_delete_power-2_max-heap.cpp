/*
Input:
5
4 3 2 5 6
Output:
Initial Max Heap: 6 5 2 3 4 
Updated Max Heap: 6 5 3 
*/

#include<iostream>
#include<vector>
using namespace std;
void swap(int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}
void insert(vector<int> &heap,int &size,int data){
    heap[size]=data;
    size++;
    int i=size-1;
    while(i>0 && heap[i]>heap[(i-1)/2]){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
void maxhepify(vector<int> &heap, int size, int i){
    int largest= i;
    int left= i*2+1;
    int right= i*2+2;
    if(left<size && heap[left]>heap[largest]) {
        largest=left;
    }
    if(right<size && heap[right]>heap[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(heap[i],heap[largest]);
        maxhepify(heap,size,largest);
    }
}
void buildmaxheap(vector<int> &heap,int size){
    for(int i=size/2-1;i>=0;i--){
        maxhepify(heap,size,i);
    }    
}
void display(vector<int> &heap, int size){
    for(int i=0;i<size;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void deletepower2(vector<int> &heap, int &size){
    int i=0;
    while(i<size){
        if(heap[i]>0 && ((heap[i]&(heap[i]-1))==0)){
            swap(heap[i],heap[size-1]);
            size--;
            maxhepify(heap,size,i);
        }
        else{
            i++;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the total numbers of elements of the heap : ";
    cin>>n;
    int size=0;
    vector<int> heap;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        insert(heap,size,data);
    }
    buildmaxheap(heap,size);
    cout<<"Initial Max-heap : ";
    display(heap,size);
    deletepower2(heap,size);
    cout<<"Updated Max-heap : ";
    display(heap,size);
    return 0;
}