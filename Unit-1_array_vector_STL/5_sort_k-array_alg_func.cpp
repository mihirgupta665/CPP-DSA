/*
Input 2 :
3
5
2 4 6 8 10
3
1 3 5
4
7 9 11 13
Output 2 :
13 11 10 9 8 7 6 5 4 3 2 1 
*/
#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;
int main(){
    int k;
    cout<<"Enter the number of arrays : "<<endl;
    cin>>k;
    vector<int> result;
    for(int l=0;l<k;l++){
        int num;
        cout<<"For "<<l+1<<" array, Enter total number of elements : ";
        cin>>num;
        vector<int> arr(num);
        for(int i =0;i<num;i++){
            cin>>arr[i];
        }
        result.insert(result.end(),arr.begin(),arr.end());
    }
    sort(result.begin(),result.end(),greater<int>());
    auto it=unique(result.begin(),result.end());
    result.erase(it,result.end()); 
    for(int ele : result){
        cout<<ele<<" ";
    }
    return 0;
}