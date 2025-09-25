/*
Input 2 :
5
1 7 9 5 6
Output 2 :
Postorder Traversal: 5 6 7 9 1 
Odd Sum: 22
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct tree {
    int value;
    tree* left=nullptr;
    tree* right=nullptr;
    tree(int data) : value(data), left(nullptr), right(nullptr) {}
};
tree* buildleveltree(vector<int> &array){
    if(array.empty()){
        return nullptr;
    }
    queue<tree*> q;
    tree* root= new tree(array[0]);
    q.push(root);
    int index=1;
    while(index<array.size()){
        tree* current=q.front();
        q.pop();
        if(index<array.size()){
            current->left = new tree(array[index]);
            q.push(current->left);
            index++;
        }
        if(index<array.size()){
            current->right = new tree(array[index]);
            q.push(current->right);
            index++;
        }
    }
    return root;
}
void postorder(tree* root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<" ";
}
int oddsum(tree* node){
    if(!node){
        return 0;
    }
    int sum=0;
    if(node->value%2!=0){
        sum+= node->value;
    }
    sum+= oddsum(node->left);
    sum+= oddsum(node->right);
    return sum;
}
int main(){
    int n;
    cout<<"Enter the total number of nodes in the tree : ";
    cin>>n;
    vector<int> array;
    for(int i=0; i<n; i++){
        int value;
        cout<<"Enter the "<<i+1<<". value : ";
        cin>>value;
        array.push_back(value);
    }
    tree* root= buildleveltree(array);
    cout<<"Post Order traversal : ";
    postorder(root);
    cout<<endl;
    int ans=oddsum(root);
    cout<<"Odd Sum : "<<ans<<endl;
    return 0;
}