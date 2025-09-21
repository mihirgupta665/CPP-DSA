/*
Input 2 :
5
106 205 101 102 104
Output 2 :
Student's height order before sorting: 106 205 101 102 104 
Height order of students after iteration 1: 101 205 106 102 104 
Height order of students after iteration 2: 101 102 106 205 104 
Height order of students after iteration 3: 101 102 104 205 106 
Height order of students after iteration 4: 101 102 104 106 205 
After final comparison of all students, the height order becomes: 101 102 104 106 205 
*/
#include<iostream>
using namespace std;
void selectionsort(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int index=i;
        for(int j=i+1;j<n;j++){
            if(arr[index]>arr[j]){
                index=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[index];
        arr[index]=temp;
        cout<<"Height order of students after iteration "<<i+1<<" : ";
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter a length of the array : ";
    cin>>n;
    int* arr= new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<". number of array : "<<endl;
        cin>>arr[i];
    }
    cout<<"Student's height order before sorting : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    selectionsort(arr,n);
    cout<<"After final comparision of all student the final height becomes : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr;
    return 0;
}