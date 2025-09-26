/*
Input 1 :
7
20 36 82 17 51 3 96
20 96
Output 1 :
Min-heap: 3 20 17 36 51 82 96 
Min-heap after deletion: 3 17 
*/

#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &heap,int a,int b){
    int temp= heap[a];
    heap[a]=heap[b];
    heap[b]=temp;
}
void minhepify(vector<int> &heap,int n, int i){
    int smallest=i;
    int left=i*2+1;
    int right=i*2+2;
    if(left<n && heap[left]<heap[i]){
        smallest=left;
    }
    if(right<n && heap[right]<heap[i]){
        smallest=right;
    }
    if(smallest!=i){
        swap(heap,i,smallest);
        minhepify(heap,n,smallest);
    }
}
void buildminheap(vector<int> &heap, int n){
    for(int i=n/2-1;i>=0;i--){
        minhepify(heap,n,i);
    }
}
void display(vector<int> &heap, int n){
    for(int i=0;i<n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void deleterange(vector<int> &heap,int start,int end, int &n){
    int size=0;
    for(int i=0;i<n;i++){
        if(heap[i]<start || heap[i]>end){
            heap[size]=heap[i];
            size++;
        }
    }
    n=size;
    buildminheap(heap,n);
}
int main(){
    int n;
    cout<<"Enter the total elements in the heap : ";
    cin>>n;
    vector<int> heap;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        heap.push_back(data);
    }
    buildminheap(heap,n);
    cout<<"Min heap before deletion : ";
    display(heap,n);
    int start,end;
    cout<<"Enter the staring range : ";
    cin>>start;
    cout<<"Enter the end range : ";
    cin>>end;
    deleterange(heap,start,end,n);
    cout<<"Min heap after deletion : ";
    display(heap,n);
    return 0;
}