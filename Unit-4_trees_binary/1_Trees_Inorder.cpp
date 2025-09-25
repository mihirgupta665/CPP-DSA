/*
Input 1 :
5
9 8 7 6 5
Output 1 :
6 8 5 9 7 
7 9 5 8 6 
Input 2 :
8
1 2 3 4 5 6 7 8
Output 2 :
8 4 2 5 1 6 3 7 
7 3 6 1 5 2 4 8 
*/
#include<iostream>
#include<vector>
using namespace std;
struct tree {
    int value;
    tree* left;
    tree* right;
    tree(int data) : value(data), left(nullptr), right (nullptr) {}
};

tree* buildtree(const vector<int> &array,int index){
    if(index>=array.size()){
        return nullptr;
    }
    tree* node= new tree(array[index]);
    node->left=buildtree(array,index*2+1);
    node->right=buildtree(array,index*2+2);
    return node;
}

void inorder(tree* root,vector<int> &result){
    if(root==nullptr){
        return;
    }
    inorder(root->left,result);
    result.push_back(root->value);
    inorder(root->right,result);
}

void rinorder(tree* root,vector<int> &result){
    if(root==nullptr){
        return;
    }
    rinorder(root->right,result);
    result.push_back(root->value);
    rinorder(root->left,result);
}
int main(){
    int n;
    cout<<"Enter the total number of values : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<". value : ";
        cin>>arr[i];
    }
    tree* root=buildtree(arr,0);
    vector<int> inordertree;
    inorder(root,inordertree);
    vector<int> rinordertree;
    rinorder(root,rinordertree);
    
    for(int val : inordertree){
        cout<<val<<" ";
    }
    cout<<endl;

    for(int val : rinordertree){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}


