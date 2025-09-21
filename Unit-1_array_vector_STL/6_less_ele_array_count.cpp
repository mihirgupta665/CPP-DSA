/*
Input 1 :
6
1 2 4 5 8 10
9
Output 1 :
5

*/
#include<iostream>
using namespace std;
int check(int arr[],int n,int key){
    int left=0;
    int right=n-1;
    int mid;
    while(left<right){
        mid=left+(right-left)/2;
        if(arr[mid]==key){
            while(mid<n-1 && arr[mid+1]==key){
                mid++;
            }
            break;
        }
        else if(arr[mid]>key){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    while(-1<mid && arr[mid]>key){
        mid--;
    }
    return mid+1;
}
int main(){
    int n;
    cout<<"Enter the number of elements in array : ";
    cin>>n;
    int* arr= new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<". number of the array : ";
        cin>>arr[i];
    }
    int ele;
    cout<<"Enter the element : ";
    cin>>ele;
    int c=check(arr, n,ele);
    cout<<"The count for num less than "<<ele<<" is : "<<c;
    delete[] arr;
    return 0;
}