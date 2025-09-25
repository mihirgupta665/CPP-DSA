/*
Input 1 :
4 
1 2 3 4
Output 1 :
4 3 1 2 
*/
#include<iostream>
#include<vector>
using namespace std;
struct tree {
    int value;
    tree* left;
    tree* right;
    tree(int data) : value(data), left(nullptr), right(nullptr) {}
};

tree* buildtree(const vector<int> &array, int index){
    if(index>=array.size()){
        return nullptr;
    }
    tree* node= new tree(array[index]);
    node->left=buildtree(array,index*2 + 1);
    node->right=buildtree(array,index*2 + 2);
    return node;
}

void collectnodes(tree* node, vector<vector<int>> &levels, int level){
    if(!node){
        return;
    }
    if(levels.size()>=level){
        levels.push_back(vector<int>());  
    }
    levels[level].push_back(node->value);
    collectnodes(node->left,levels,level+1);
    collectnodes(node->right,levels,level+1);
}

void ralternatenodes(tree* root, vector<vector<int>> &levels,int level){
    if(!root){
        return;
    }
    if(level%2==1){
        root->value=levels[level].back();
        levels[level].pop_back();
    }
    ralternatenodes(root->left,levels,level+1);
    ralternatenodes(root->right,levels,level+1);
    return;
}

void inordertraversal(tree* root,vector<int> &result){
    if(!root){
        return;
    }
    inordertraversal(root->left,result);
    result.push_back(root->value);
    inordertraversal(root->right,result);
    return;
}

int main(){
    int n;
    cout<<"Enter the total nodes of tree : ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<". value : ";
        cin>>arr[i];
    }
    tree* root= buildtree(arr,0);
    vector<vector<int>> levels;
    collectnodes(root,levels,0);
    ralternatenodes(root,levels,0);
    vector<int> inordertree;
    inordertraversal(root,inordertree);
    for(int val : inordertree){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}