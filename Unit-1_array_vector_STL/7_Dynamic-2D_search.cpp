/*
Input 1 :
3
3
1 2 3
4 5 6
7 8 9
5
Output 1 :
[1][1]
*/

#include<iostream>
using namespace std;
bool check(int** arr, int row, int colm,int key){
    for(int i=0;i<row;i++){
        for(int j=0;j<row;j++){
            if(arr[i][j]==key){
                cout<<"Element "<<key<<" found at "<<"["<<i<<"]"<<"["<<j<<"]"<<endl;
                return true;
            }
        }
    }
    return false;
}
int main(){
    int row,colm;
    cout<<"Enter the number of rows : ";
    cin>>row;
    cout<<"Enter the number of column : ";
    cin>>colm;
    int** arr=new int*[row];
    for(int i=0;i<row;i++){
        arr[i]=new int[colm];
        for(int j=0;j<colm;j++){
            cin>>arr[i][j];
        }
    }
    int ele;
    cout<<"Enter the element to search : ";
    cin>>ele;
    bool ans=check(arr,row,colm,ele);
    if(!ans){
        cout<<"Element "<<ele<<" not found.";
    }
    return 0;
}