/*
Input 2 :
9
7 10 11 3 6 9 2 13 0
Output 2 :
11 3 7 9 6 10 2 13 0 
*/

#include<iostream>
using namespace std;
void evenoddinsertion(int* arr,int n){
    for(int i=2;i<n;i++){
        if(i%2==1){
            int check=arr[i];
            int j;
            for(j=i-2;j>=0 && arr[j]>check;j-=2){
                arr[j+2]=arr[j];
            }
            arr[j+2]=check;
        }
        else{
            int check=arr[i];
            int j;
            for( j=i-2;j>=0 && arr[j]<check;j-=2){
                arr[j+2]=arr[j];
            }
            arr[j+2]=check;
        }
    }
}
int main(){
    int n;
    cout<<"Enter the number of elements in the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    evenoddinsertion(arr,n);
    cout<<"Array after sorting is : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}