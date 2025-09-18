/*
Input 1 :
5
apple
banana
avocado
grape
orange
a
Output 1 :
2
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of strings : ";
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        v.push_back(str);
    }
    char ch;
    cout<<"Enter a character to be searched in each word : ";
    cin>>ch;
    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i][0]==ch){
            count++;
        }
    }
    cout<<"The number of the word which start with '"<<ch<<"' are : "<<count<<endl;
    return 0;
}
